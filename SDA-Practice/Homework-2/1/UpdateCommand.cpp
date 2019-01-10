#include "UpdateCommand.h"

UpdateCommand::UpdateCommand() {
  db = new StudentDb();
}

UpdateCommand::~UpdateCommand() {
  delete db;
}

void UpdateCommand::execute() {
  long long fn;
  std::string firstname;
  std::string lastname;
  short grade;

  std::cin >> fn >> firstname >> lastname >> grade;
  try {
    bool found = db->update(Student(fn, firstname, lastname, grade));

    if (found) {
      std::cout << "Record saved!" << std::endl;
    } else {
      std::cout << "Record not found!" << std::endl;
    }
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return;
  }
}
