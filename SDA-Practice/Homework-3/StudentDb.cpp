#include "StudentDb.h"

StudentDb::StudentDb() { }

StudentDb::~StudentDb() {

}

const std::string StudentDb::DbName = "StudentsGrades.db";

void StudentDb::create(Student entry) {
  std::ofstream outfile;
  outfile.open(StudentDb::DbName.c_str(), std::ios_base::app);
  outfile << entry.getFn() << " "
          << entry.getFirstname() << " "
          << entry.getLastname() << " "
          << entry.getGrade() << "\n";

  outfile.close();
}

Student* StudentDb::fetch(long long location) {
  std::ifstream fin;
  std::string line;
  fin.open(StudentDb::DbName.c_str());
  fin.seekg(location);

  long long fn;
  std::string firstName, lastName;
  short grade;

  getline(fin, line);
  std::stringstream ss(line);
  ss >> fn >> firstName >> lastName >> grade;

  return new Student(fn, firstName, lastName, grade);
}

Student* StudentDb::find(long long id) {
  Student *match = NULL;
  std::string line;
  std::ifstream fin;
  fin.open(StudentDb::DbName.c_str());
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
