#include "SequentialSearchCommand.h"

SequentialSearchCommand::SequentialSearchCommand() {
  db = new StudentDb();
}

SequentialSearchCommand::~SequentialSearchCommand() {
  delete db;
}

void SequentialSearchCommand::execute() {
  int facultyNumber;
  std::cin >> facultyNumber;

  Student *student = db->find(facultyNumber);
  if (student == NULL) {
    std::cerr << "No records available" << std::endl;
    return;
  }

  std::cout << student->getFn() << " "
       << student->getFirstname() << " "
       << student->getLastname() << " "
       << student->getGrade() << std::endl;

  delete student;
}
