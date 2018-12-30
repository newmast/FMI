#include "FacultyNumberIndexDb.h"

FacultyNumberIndexDb::FacultyNumberIndexDb() {
  fin = new std::ifstream;
  fin->open(FacultyNumberIndexDb::IndexName.c_str(), std::ios::binary);
}

FacultyNumberIndexDb::~FacultyNumberIndexDb() {
  fin->close();
  delete fin;
}

const std::string FacultyNumberIndexDb::IndexName = "FacultyNumber.ids";

void FacultyNumberIndexDb::create(FacultyNumberIndex entry) {
  throw "Not a requirement yet.";
}

long long FacultyNumberIndexDb::binarySearchRecord(long long left, long long right, long long target) {
  if (right >= left) {
        long long mid = left + (right - left) / 2;
        FacultyNumberIndex* current = fetch(mid);

        long long facultyNumber = current->facultyNumber;
        long long dbLocation = current->dbLocation;
        delete current;

        if (facultyNumber == target)
            return dbLocation;

        if (facultyNumber > target)
          return binarySearchRecord(left, mid - 1, target);

        return binarySearchRecord(mid + 1, right, target);
    }

    return -1;
}


FacultyNumberIndex* FacultyNumberIndexDb::fetch(long long location) {
  fin->seekg(location * sizeof(FacultyNumberIndex));
  FacultyNumberIndex current;
  fin->read((char*)&current, sizeof(FacultyNumberIndex));
  return new FacultyNumberIndex(current);
}


FacultyNumberIndex* FacultyNumberIndexDb::find(long long facultyNumber) {
  fin->seekg(0, fin->end);
  long long numberOfEntries = fin->tellg() / sizeof(FacultyNumberIndex);
  fin->seekg(0, fin->beg);

  long long dbLocation = binarySearchRecord(0, numberOfEntries-1, facultyNumber);
  if (dbLocation == -1) {
    return NULL;
  }

  FacultyNumberIndex* result = new FacultyNumberIndex;
  result->facultyNumber = facultyNumber;
  result->dbLocation = dbLocation;
  return result;
}
