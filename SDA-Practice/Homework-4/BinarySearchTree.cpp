#include "BinarySearchTree.h"

void BinarySearchTree::insert(Node *node, Student student) {
  if (node->student.fn > student.fn) {
    if (node->left == NULL) {
      node->left = new Node;
      node->left->student = student;
      std::cout << "Record inserted!" << std::endl;
    } else {
      insert(node->left, student);
    }
  } else {
    if (node->right == NULL) {
      node->right = new Node;
      node->right->student = student;
      std::cout << "Record inserted!" << std::endl;
    } else {
      insert(node->right, student);
    }
  }
}

void BinarySearchTree::find(Node* node, long long value) {
  if (node == NULL) {
    std::cout << "Record not found!" << std::endl;
    return;
  }

  if (node->student.fn > value) {
    find(node->left, value);
  } else if (node->student.fn < value) {
    find(node->right, value);
  } else if (node->student.fn == value) {
    std::cout << node->student.fn << " "
         << node->student.firstName << " "
         << node->student.lastName << std::endl;
  }
}

Node* BinarySearchTree::getLeftmost(Node *node) {
  if (node->left == NULL) return node;
  getLeftmost(node->left);
}

Node* BinarySearchTree::remove(Node* node, long long value) {
  if (node == NULL) {
    std::cerr << "Record not found!" << std::endl;
    return node;
  }
  if (node->student.fn > value) {
    node->left = remove(node->left, value);
  } else if (node->student.fn < value) {
    node->right = remove(node->right, value);
  } else {
    if (node->left == NULL && node->right == NULL) {
      std::cout << "Record deleted!" << std::endl;
      return NULL;
    } else if (node->left == NULL) {
      Node* temp = node->right;
      delete node;
      std::cout << "Record deleted!" << std::endl;
      return temp;
    } else if (node->right == NULL) {
      Node* temp = node->left;
      delete node;
      std::cout << "Record deleted!" << std::endl;
      return temp;
    }

    Node* temp = getLeftmost(node->right);
    node->student = temp->student;
    node->right = remove(node->right, temp->student.fn);
  }

  return node;
}

void BinarySearchTree::traverse(Node *node) {
  if (node->left != NULL) {
    traverse(node->left);
    std::cout << ", ";
  }

  std::cout << node->student.fn << " ";

  if (node->right != NULL) {
    std::cout << ", ";
    traverse(node->right);
  }

}

void BinarySearchTree::insert(Student student) {
  if (root == NULL) {
    root = new Node;
    root->student = student;
    std::cout << "Record inserted!" << std::endl;
    return;
  }

  insert(root, student);
}

void BinarySearchTree::remove(long long value) {
  root = remove(root, value);
}

void BinarySearchTree::find(long long value) {
  find(root, value);
}

void BinarySearchTree::traverse() {
  traverse(root);
  std::cout << std::endl;
}
