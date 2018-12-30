#pragma once

#include "ICommand.h"
#include "IRepository.h"
#include "Student.h"
#include "FacultyNumberIndex.h"
#include "FacultyNumberIndexDb.h"
#include "StudentDb.h"

/*
 * Binary search index
 */
class FastSearchCommand : public ICommand {
  IRepository<FacultyNumberIndex> *index;
  IRepository<Student> *db;
public:
  FastSearchCommand();
  ~FastSearchCommand();
  virtual void execute();
};
