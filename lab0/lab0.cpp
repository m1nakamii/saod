#include <iostream>

// Структура узла дерева
struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
};

// Создание нового узла
TreeNode *createNode(int data) {
  TreeNode *newNode = new TreeNode;
  newNode->data = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

// Функция для добавления узла в дерево
TreeNode *insert(TreeNode *root, int data) {
  if (root == nullptr) {
    return createNode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }

  return root;
}

// Обходы дерева
void inorderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;
  inorderTraversal(root->left);
  std::cout << root->data << " ";
  inorderTraversal(root->right);
}

void preorderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;
  std::cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  std::cout << root->data << " ";
}

// Вычисление размера дерева
int treeSize(TreeNode *root) {
  if (root == nullptr)
    return 0;
  return 1 + treeSize(root->left) + treeSize(root->right);
}

// Вычисление контрольной суммы
int treeSum(TreeNode *root) {
  if (root == nullptr)
    return 0;
  return root->data + treeSum(root->left) + treeSum(root->right);
}

// Вычисление высоты дерева
int treeHeight(TreeNode *root) {
  if (root == nullptr)
    return 0;
  int leftHeight = treeHeight(root->left);
  int rightHeight = treeHeight(root->right);
  return 1 + std::max(leftHeight, rightHeight);
}

int main() {
  TreeNode *root = nullptr;

  // Заполнение дерева данными (замените значениями по вашему выбору)
  int data[] = {10, 7, 12, 9, 8, 13};
  int n = sizeof(data) / sizeof(data[0]);
  for (int i = 0; i < n; ++i) {
    root = insert(root, data[i]);
  }

  std::cout << "Обход слева направо: ";
  inorderTraversal(root);
  std::cout << std::endl;

  std::cout << "Обход сверху вниз: ";
  preorderTraversal(root);
  std::cout << std::endl;

  std::cout << "Обход снизу вверх: ";
  postorderTraversal(root);
  std::cout << std::endl;

  int size = treeSize(root);
  int sum = treeSum(root);
  int height = treeHeight(root);

  std::cout << "Размер дерева: " << size << std::endl;
  std::cout << "Контрольная сумма: " << sum << std::endl;
  std::cout << "Высота дерева: " << height << std::endl;

  return 0;
}