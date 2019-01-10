#pragma once

#include <iostream>

/*
 * Data class the represents a single Student.
 */
class Student {
  long long facultyNumber_;
  std::string firstName_;
  std::string lastName_;
  short grade_;

public:
  Student(long long fn, std::string firstName, std::string lastName, short grade);

  long long getFn();
  void setFn(long long fn);

  std::string getFirstname();
  void setFirstname(std::string value);

  std::string getLastname();
  void setLastname(std::string value);

  short getGrade();
  void setGrade(short grade);
};
