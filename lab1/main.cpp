#include <cmath>
#include <iostream>

using namespace std;

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  int size; // размер поддерева с корнем в данной вершине
} Node;

Node *createNode(int data) {
  Node *newNode = new Node();
  if (!newNode) {
    cout << "Ошибка: Не удалось выделить память." << endl;
    return nullptr;
  }
  newNode->data = data;
  newNode->left = newNode->right = nullptr;
  newNode->size = 1;
  return newNode;
}

Node *sortedArrayToBST(int arr[], int start, int end) {
  if (start > end)
    return nullptr;

  int mid = (start + end) / 2;
  Node *root = createNode(arr[mid]);

  root->left = sortedArrayToBST(arr, start, mid - 1);
  root->right = sortedArrayToBST(arr, mid + 1, end);

  // Обновляем размер поддерева
  if (root->left)
    root->size += root->left->size;
  if (root->right)
    root->size += root->right->size;

  return root;
}

//->
void Obhod(Node *root) {
  if (root != nullptr) {
    cout << root->data << " ";
    Obhod(root->left);
    Obhod(root->right);
  }
}

int size(Node *root) {
  if (root == NULL) {
    return 0;
  } else {
    return 1 + size(root->left) + size(root->right);
  }
}

int Height(Node *root) {
  if (root == NULL) {
    return 0;
  } else {
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
  }
}

int SumLenghtWay(Node *tree, int L) {
  int s = 0;
  if (tree == NULL) {
    s = 0;
  } else {
    s = L + SumLenghtWay(tree->left, L + 1) + SumLenghtWay(tree->right, L + 1);
  }
  return s;
}

int Checksum(Node *root) {
  if (root == NULL) {
    return 0;
  } else {
    return root->data + Checksum(root->left) + Checksum(root->right);
  }
}

int main() {
  srand(time(nullptr)); // Инициализация генератора случайных чисел

  int n = 100;

  int arr[n];
  for (int i = 0; i < n; ++i)
    arr[i] = rand() % 1000; // Генерация случайных ключей от 0 до 99

  Node *root = sortedArrayToBST(arr, 0, n - 1);

  cout << "обход исдп:" << endl;
  Obhod(root);

  int treesize = size(root);
  int treeheight = Height(root);
  int checksum = Checksum(root);
  double avgHeight = (double)SumLenghtWay(root, 1) / treesize;

  cout << "\n\nРазмер дерева: " << treesize << endl;
  cout << "Высота дерева: " << treeheight << endl;
  cout << "Контрольная сумма: " << checksum << endl;
  cout << "Средняя высота: " << avgHeight << endl;
}