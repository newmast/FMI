#pragma once

#include <iostream>
#include <string>

#include "ICommand.h"
#include "BinarySearchTree.h"

class InsertCommand : public ICommand {
  BinarySearchTree* tree;
public:
  InsertCommand(BinarySearchTree* tree);
  ~InsertCommand();
  virtual void execute();
};
