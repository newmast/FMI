#pragma once

#include <iostream>
#include <string>

#include "ICommand.h"

#include "BinarySearchTree.h"

class TraverseCommand : public ICommand {
  BinarySearchTree* tree;
public:
  TraverseCommand(BinarySearchTree* tree);
  ~TraverseCommand();
  virtual void execute();
};
