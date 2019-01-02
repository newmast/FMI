#pragma once

#include <iostream>
#include <map>

#include "ICommand.h"

/*
 * Registers commands and executes them.
 */
class CommandResolver {
  std::map<std::string, ICommand*> resolver;

public:
 ~CommandResolver();
 void registerCommand(std::string name, ICommand *command);
 void execute(std::string command);
};
