#include "InsertCommand.h"

#include "Student.h"

InsertCommand::InsertCommand(BinarySearchTree* tree)
  : tree(tree) {}

InsertCommand::~InsertCommand() {
}

void InsertCommand::execute() {
  Student s;
  std::cin >> s.fn >> s.firstName >> s.lastName;

  tree->insert(s);
}
