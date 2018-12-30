#pragma once

#include "FacultyNumberIndex.h"
#include "Student.h"
#include "IRepository.h"
#include <fstream>
#include <sstream>
#include <string>

/*
 * Implementation of the repository interface that persists data in a file.
 */
class FacultyNumberIndexDb : public IRepository<FacultyNumberIndex> {
private:
  long long binarySearchRecord(long long left, long long right, long long target);

  std::ifstream* fin;
public:
  static const std::string IndexName;

  FacultyNumberIndexDb();

  ~FacultyNumberIndexDb();

  virtual void create(FacultyNumberIndex entry);

  virtual FacultyNumberIndex* find(long long facultyNumber);

  virtual FacultyNumberIndex* fetch(long long location);
};
