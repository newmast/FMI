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

  long long getFn() const;
  void setFn(long long fn);

  std::string getFirstname() const;
  void setFirstname(std::string value);

  std::string getLastname() const;
  void setLastname(std::string value);

  short getGrade() const;
  void setGrade(short grade);

  friend std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.getFn() << " "
       << student.getFirstname() << " "
       << student.getLastname() << " "
       << student.getGrade();

    return os;
  }
};
