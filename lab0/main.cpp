#include <iostream>

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int data) {
  if (root == nullptr) {
    return new Node(data);
  } else {
    if (data <= root->data) {
      root->left = insert(root->left, data);
    } else {
      root->right = insert(root->right, data);
    }
  }
  return root;
}

// Обход слева направо (pre-order)
void leftright(Node *root) {
  if (root != nullptr) {
    std::cout << root->data << " ";
    leftright(root->left);
    leftright(root->right);
  }
}

// Обход сверху вниз (in order)
void updown(Node *root) {
  if (root != nullptr) {
    updown(root->left);
    std::cout << root->data << " ";
    updown(root->right);
  }
}

// Обход снизу вверх (post-order)
void downup(Node *root) {
  if (root != nullptr) {
    downup(root->left);
    downup(root->right);
    std::cout << root->data << " ";
  }
}

int main() {
  Node *root = nullptr;

  // Заполнение дерева данными (3 вариант)
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 9);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 8);

  // Вывод обходов дерева

  std::cout << "Обход слева направо (pre order): ";
  leftright(root);
  std::cout << std::endl;

  std::cout << "Обход сверху вниз (in order): ";
  updown(root);
  std::cout << std::endl;

  std::cout << "Обход снизу вверх (post order): ";
  downup(root);
  std::cout << std::endl;

  return 0;
}