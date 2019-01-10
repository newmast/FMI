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
class DeleteCommand : public ICommand {
  IRepository<Student> *db;
public:
  DeleteCommand();
  ~DeleteCommand();
  virtual void execute();
};
