#include <iostream>
#include <string>

#include "CommandResolver.h"
#include "InsertCommand.h"
#include "BinarySearchTree.h"
#include "DeleteCommand.h"
#include "FindCommand.h"
#include "TraverseCommand.h"
#include "Student.h"
#include "ExitCommand.h"

int main() {
  bool running = true;

  BinarySearchTree* tree = new BinarySearchTree;

  CommandResolver resolver;
  resolver.registerCommand("insert", new InsertCommand(tree));
  resolver.registerCommand("delete", new DeleteCommand(tree));
  resolver.registerCommand("find", new FindCommand(tree));
  resolver.registerCommand("traverseInorder", new TraverseCommand(tree));
  resolver.registerCommand("exit", new ExitCommand(&running));

  std::string input;
  while(running) {
    std::cin >> input;
    resolver.execute(input);
  }

  delete tree;

  return 0;
}
