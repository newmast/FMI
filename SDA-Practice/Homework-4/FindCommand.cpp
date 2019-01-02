#include "FindCommand.h"

FindCommand::FindCommand(BinarySearchTree* tree)
  : tree(tree) {}

FindCommand::~FindCommand() {
}

void FindCommand::execute() {
  long long id;
  std::cin >> id;
  tree->find(id);
}
