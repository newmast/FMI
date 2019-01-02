#pragma once

#include <iostream>
#include <string>

#include "ICommand.h"

#include "BinarySearchTree.h"

class FindCommand : public ICommand {
  BinarySearchTree* tree;
public:
  FindCommand(BinarySearchTree* tree);
  ~FindCommand();
  virtual void execute();
};
