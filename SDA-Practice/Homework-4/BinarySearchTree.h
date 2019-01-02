#pragma once

#include "Node.h"

class BinarySearchTree {
  Node* root;
  void insert(Node *node, Student student);
  void find(Node* node, long long value);
  Node* getLeftmost(Node *node);
  Node* remove(Node* node, long long value);
  void traverse(Node *node);
public:
  void insert(Student student);
  void remove(long long value);
  void find(long long value);
  void traverse();
};
