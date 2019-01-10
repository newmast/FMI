#include "DeleteCommand.h"

DeleteCommand::DeleteCommand() {
  db = new StudentDb();
}

DeleteCommand::~DeleteCommand() {
  delete db;
}

void DeleteCommand::execute() {
  long long fn;
  std::cin >> fn;

  try {
    bool found = db->remove(fn);

    if (found) {
      std::cout << "Record deleted!" << std::endl;
    } else {
      std::cout << "Record not found!" << std::endl;
    }
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return;
  }
}
