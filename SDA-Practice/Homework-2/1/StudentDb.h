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

  virtual Student* find(long long id);

  virtual bool update(Student entry);

  virtual bool remove(long long id);
};
