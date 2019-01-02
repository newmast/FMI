#include "TraverseCommand.h"

TraverseCommand::TraverseCommand(BinarySearchTree* tree)
  : tree(tree) {}

TraverseCommand::~TraverseCommand() {
}

void TraverseCommand::execute() {
  tree->traverse();
}
