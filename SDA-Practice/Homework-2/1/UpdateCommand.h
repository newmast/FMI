#pragma once

#include <iostream>
#include <string>

#include "Student.h"
#include "IRepository.h"
#include "ICommand.h"
#include "StudentDb.h"

/*
 * Command that is responsible for creating students.
 */
class UpdateCommand : public ICommand {
  IRepository<Student> *db;
public:
  UpdateCommand();
  ~UpdateCommand();
  virtual void execute();
};
