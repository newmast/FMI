#include "BuildIndexCommand.h"
#include <string>
BuildIndexCommand::BuildIndexCommand() { }

BuildIndexCommand::~BuildIndexCommand() { }

bool BuildIndexCommand::sortFunction(FacultyNumberIndex a, FacultyNumberIndex b) {
  return a.facultyNumber < b.facultyNumber;
}


void BuildIndexCommand::execute() {
  std::string line;
  std::ifstream fin;
  fin.open(StudentDb::DbName.c_str(), std::ios::binary);

  std::vector<FacultyNumberIndex> index;
  while(!fin.eof())
  {
      FacultyNumberIndex current;
      current.dbLocation = fin.tellg();

      getline(fin, line);
      std::stringstream ss(line);
      ss >> current.facultyNumber;

      index.push_back(current);
  }

  index.pop_back(); // deletes final newline

  // std::sorts has a n*log(n) default complexity
  // https://en.cppreference.com/w/cpp/algorithm/sort
  std::sort(index.begin(), index.end() , BuildIndexCommand::sortFunction);

  fin.close();

  std::ofstream fout;
  fout.open(FacultyNumberIndexDb::IndexName.c_str(), std::ios::binary);
  for (long long i = 0; i < index.size(); i++) {
    fout.write((char*)&index[i], sizeof(FacultyNumberIndex));
  }

  fout.close();

  std::cout << "Index is built!" << std::endl;
}
