#include "SequentialSearchCommand.h"

SequentialSearchCommand::SequentialSearchCommand() {
  db = new StudentDb();
}

SequentialSearchCommand::~SequentialSearchCommand() {
  delete db;
}

void SequentialSearchCommand::execute() {
  long long facultyNumber;
  std::cin >> facultyNumber;

  Student *student = db->find(facultyNumber);
  if (student == NULL) {
    std::cerr << "Record not found!" << std::endl;
    return;
  }

  std::cout << *student << std::endl;

  delete student;
}
