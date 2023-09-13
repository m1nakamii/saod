#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

struct Record {
  char author[12];
  char title[32];
  char publisher[16];
  short int year;
  short int num_of_page;
};

void merge(Record arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  Record leftArr[n1];
  Record rightArr[n2];

  for (int i = 0; i < n1; i++)
    leftArr[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    rightArr[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (strcmp(leftArr[i].title, rightArr[j].title) <= 0) {
      arr[k] = leftArr[i];
      i++;
    } else {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

void mergeSort(Record arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int main() {

  FILE *fp;
  fp = fopen("testBase1.dat", "rb");

  if (!fp) {
    cerr << "Ошибка при открытии файла." << endl;
    return 1;
  }
  Record tt[4000] = {0};
  int i = fread((Record *)tt, sizeof(Record), 4000, fp);

  mergeSort(tt, 0, i - 1);

  for (int i = 0; i < 4000; ++i)
    cout << tt[i].author << "\t" << tt[i].title << "\t" << tt[i].publisher
         << "\t" << tt[i].year << "\t" << tt[i].num_of_page << endl;
  cout << "Прочитано записей: " << i << endl;
  fclose(fp);
  return 0;
}