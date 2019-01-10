#pragma once

#include "ICommand.h"
#include "IRepository.h"
#include "Student.h"
#include "StudentDb.h"

/*
 * The command responsible for linearly searching the database file.
 */
class SequentialSearchCommand : public ICommand {
  IRepository<Student> *db;
public:
  SequentialSearchCommand();
  ~SequentialSearchCommand();
  virtual void execute();
};
