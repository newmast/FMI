#include "CreateCommand.h"

CreateCommand::CreateCommand() {
  db = new StudentDb();
}

CreateCommand::~CreateCommand() {
  delete db;
}

void CreateCommand::execute() {
  long long fn;
  std::string firstname;
  std::string lastname;
  short grade;

  std::cin >> fn >> firstname >> lastname >> grade;
  try {
    db->create(Student(fn, firstname, lastname, grade));
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return;
  }
  std::cout << "Record saved!" << std::endl;
}
