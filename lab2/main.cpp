#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

struct TreeNode {
  int data;
  int key;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

TreeNode *insert_recursive(TreeNode *root, int key) {
  if (root == nullptr) {
    return new TreeNode(key);
  }
  if (key < root->key) {
    root->left = insert_recursive(root->left, key);
  } else if (key > root->key) {
    root->right = insert_recursive(root->right, key);
  }
  // Устанавливаем значение data равным ключу (можно использовать что-то другое)
  root->data = key;
  return root;
}

TreeNode *insert_with_double_indirection(TreeNode *root, int key) {
  TreeNode **current = &root;
  while (*current != nullptr) {
    if (key < (*current)->key) {
      current = &((*current)->left);
    } else if (key > (*current)->key) {
      current = &((*current)->right);
    } else {
      // Уже существует вершина с таким ключом, не добавляем дубликаты
      return root;
    }
  }
  *current = new TreeNode(key);
  // Устанавливаем значение data равным ключу (можно использовать что-то другое)
  (*current)->data = key;
  return root;
}

void inorderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  inorderTraversal(root->left);
  std::cout << root->key << " ";
  inorderTraversal(root->right);
}

int size(TreeNode *root) {
  if (root == NULL) {
    return 0;
  } else {
    return 1 + size(root->left) + size(root->right);
  }
}

int Height(TreeNode *root) {
  if (root == NULL) {
    return 0;
  } else {
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
  }
}

int SumLenghtWay(TreeNode *tree, int L) {
  int s = 0;
  if (tree == NULL) {
    s = 0;
  } else {
    s = L + SumLenghtWay(tree->left, L + 1) + SumLenghtWay(tree->right, L + 1);
  }
  return s;
}

int Checksum(TreeNode *root) {
  if (root == NULL) {
    return 0;
  } else {
    return root->data + Checksum(root->left) + Checksum(root->right);
  }
}

int main() {
  srand(static_cast<unsigned>(time(nullptr)));
  TreeNode *root_recursive = nullptr;
  TreeNode *root_double_indirection = nullptr;
  const int numNodes = 100; // Количество вершин в дереве

  for (int i = 0; i < numNodes; ++i) {
    int key = rand() % 1000; // Генерация случайного ключа
    root_recursive = insert_recursive(root_recursive, key);
    root_double_indirection =
        insert_with_double_indirection(root_double_indirection, key);
  }

  cout << "Дерево, построенное рекурсивным методом:" << endl;
  inorderTraversal(root_recursive);
  cout << endl;

  cout << "Дерево, построенное с использованием двойной косвенности:" << endl;
  inorderTraversal(root_double_indirection);
  cout << endl;

  int treesize = size(root_recursive);
  int treeheight = Height(root_recursive);
  int checksum = Checksum(root_recursive);
  double avgHeight = (double)SumLenghtWay(root_recursive, 1) / treesize;

  cout << "\nРазмер дерева, построенного рекурсивным методом: " << treesize
       << endl;
  cout << "Высота дерева, построенного рекурсивным методом: " << treeheight
       << endl;
  cout << "Контрольная сумма дерева, построенного рекурсивным методом: "
       << checksum << endl;
  cout << "Средняя высота дерева, построенного рекурсивным методом: "
       << avgHeight << endl;

  int treesize2 = size(root_double_indirection);
  int treeheight2 = Height(root_double_indirection);
  int checksum2 = Checksum(root_double_indirection);
  double avgHeight2 =
      (double)SumLenghtWay(root_double_indirection, 1) / treesize;

  cout << "\nРазмер дерева, построенного с использованием двойной косвенности: "
       << treesize2 << endl;
  cout << "Высота дерева, построенного с использованием двойной косвенности: "
       << treeheight2 << endl;
  cout << "Контрольная сумма дерева, построенного с использованием двойной "
          "косвенности: "
       << checksum2 << endl;
  cout << "Средняя высота дерева, построенного с использованием двойной "
          "косвенности: "
       << avgHeight2 << endl;
  return 0;
}