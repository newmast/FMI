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
public:
  static const std::string DbName;

  StudentDb();

  ~StudentDb();

  virtual void create(Student entry);

  virtual Student* find(long long id);

  virtual Student* fetch(long long location);
};
