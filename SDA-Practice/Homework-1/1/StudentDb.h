#pragma once

#include "Student.h"
#include "IRepository.h"
#include <fstream>
#include <sstream>
#include <string>

/*
 * Implementation of the repository interface that persists data in a file.
 */
class StudentDb : public IRepository<Student> {
  const std::string dbName;
public:
  StudentDb();

  virtual void create(Student entry);

  virtual Student* find(int id);
};
