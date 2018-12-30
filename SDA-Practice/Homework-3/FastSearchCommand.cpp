#include "FastSearchCommand.h"

FastSearchCommand::FastSearchCommand() {
  index = new FacultyNumberIndexDb();
  db = new StudentDb();
}

FastSearchCommand::~FastSearchCommand() {
  delete db;
  delete index;
}

void FastSearchCommand::execute() {
  long long facultyNumber;
  std::cin >> facultyNumber;

  FacultyNumberIndex* recordLocation = index->find(facultyNumber);

  if (recordLocation == NULL) {
    std::cerr << "Record not found!" << std::endl;
    return;
  }

  Student* student = db->fetch(recordLocation->dbLocation);
  if (student == NULL) {
    std::cerr << "Record not found!" << std::endl;
  }
  else {
    std::cout << *student << std::endl;
    delete student;
  }

  delete recordLocation;
}
