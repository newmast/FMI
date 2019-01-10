#include "Student.h"

Student::Student(long long fn, std::string firstName, std::string lastName, short grade) {
  setFn(fn);
  setFirstname(firstName);
  setLastname(lastName);
  setGrade(grade);
}

long long Student::getFn() { return facultyNumber_; }

void Student::setFn(long long fn) {
  if (fn <= 0 || fn > 1125899906842624LL) {
    throw std::invalid_argument("Invalid faculty number");
  }

  facultyNumber_ = fn;
}

std::string Student::getFirstname() { return firstName_; }

void Student::setFirstname(std::string value) {
  if (value.size() > 128) {
    throw std::invalid_argument("Invalid first name");
  }

  firstName_ = value;
}

std::string Student::getLastname() { return lastName_; }

void Student::setLastname(std::string value) {
  if (value.size() > 128) {
    throw std::invalid_argument("Invalid last name");
  }

  lastName_ = value;
}

short Student::getGrade() { return grade_; }

void Student::setGrade(short grade) {
  if (grade < 2 || grade > 6) {
    throw std::invalid_argument("Invalid grade");
  }

  grade_ = grade;
}
