#pragma once

#include "ICommand.h"
#include "FacultyNumberIndex.h"
#include "FacultyNumberIndexDb.h"
#include "StudentDb.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

/*
  TODO: Save location of data and sort records by FN
 */
class BuildIndexCommand : public ICommand {
private:
  static bool sortFunction(FacultyNumberIndex a, FacultyNumberIndex b);
public:
  BuildIndexCommand();
  ~BuildIndexCommand();
  virtual void execute();
};
