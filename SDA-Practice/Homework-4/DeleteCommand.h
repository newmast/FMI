#pragma once

#include <iostream>
#include <string>

#include "ICommand.h"

#include "BinarySearchTree.h"


class DeleteCommand : public ICommand {
  BinarySearchTree* tree;
public:
  DeleteCommand(BinarySearchTree* tree);
  ~DeleteCommand();
  virtual void execute();
};
