#include "StudentDb.h"

StudentDb::StudentDb()
  : dbName("StudentsGrades.db") { }

void StudentDb::create(Student entry) {
  std::ofstream outfile;
  outfile.open(dbName.c_str(), std::ios_base::app);
  outfile << entry.getFn() << " "
          << entry.getFirstname() << " "
          << entry.getLastname() << " "
          << entry.getGrade() << "\n";

  outfile.close();
}

Student* StudentDb::find(int id) {
  Student *match = NULL;
  std::string line;
  std::ifstream fin;
  fin.open(dbName.c_str());
  while(!fin.eof())
  {
      int fn;

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

  return match;
}
