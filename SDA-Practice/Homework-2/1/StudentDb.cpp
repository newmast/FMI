#include "StudentDb.h"
#include <stdio.h>

StudentDb::StudentDb()
  : dbName("StudentsGrades.db") {
}

bool StudentDb::update(Student entry) {
  std::string line;
  std::ifstream fin;
  std::ofstream outfile;
  outfile.open("temp.db");

  bool found = false;
  fin.open(dbName.c_str());
  while(!fin.eof())
  {
      long long fn;

      getline(fin, line);
      std::stringstream ss(line);
      ss >> fn;

      if (entry.getFn() != fn && line.length() > 0) {
        outfile << line << "\n";
      }

      if (entry.getFn() == fn && line.length() > 0) {
        found = true;
        outfile << entry.getFn() << " "
                << entry.getFirstname() << " "
                << entry.getLastname() << " "
                << entry.getGrade() << "\n";
      }
  }

  fin.close();
  outfile.close();

  std::remove(dbName.c_str());
  rename("temp.db", dbName.c_str());

  return found;
}

bool StudentDb::remove(long long id) {
  std::string line;
  std::ifstream fin;
  std::ofstream outfile;
  outfile.open("temp.db");

  bool found = false;
  fin.open(dbName.c_str());
  while(!fin.eof())
  {
      long long fn;

      getline(fin, line);
      std::stringstream ss(line);
      ss >> fn;

      if (id != fn && line.length() > 0) {
        outfile << line << "\n";
      }

      if (id == fn)
        found = true;
  }

  fin.close();
  outfile.close();

  std::remove(dbName.c_str());
  rename("temp.db", dbName.c_str());

  return found;
}

Student* StudentDb::find(long long id) {
  Student *match = NULL;
  std::string line;
  std::ifstream fin;
  fin.open(dbName.c_str());
  while(!fin.eof())
  {
      long long fn;

      getline(fin, line);
      std::stringstream ss(line);
      ss >> fn;

      if (id == fn) {
        std::string firstName;
        std::string lastName;
        short grade;

        ss >> firstName >> lastName >> grade;
        match = new Student(fn, firstName, lastName, grade);
        break;
      }
  }

  fin.close();

  return match;
}
