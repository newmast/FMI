#include "DeleteCommand.h"

DeleteCommand::DeleteCommand(BinarySearchTree* tree)
  : tree(tree) {}

DeleteCommand::~DeleteCommand() {
}

void DeleteCommand::execute() {
  long long id;
  std::cin >> id;

  tree->remove(id);
}
