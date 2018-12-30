#include <iostream>
#include <string>

#include "CommandResolver.h"
#include "CreateCommand.h"
#include "SequentialSearchCommand.h"
#include "BuildIndexCommand.h"
#include "FastSearchCommand.h"
#include "ExitCommand.h"

int main() {
  bool running = true;

  CommandResolver resolver;
  resolver.registerCommand("create", new CreateCommand);
  resolver.registerCommand("search", new FastSearchCommand);
  resolver.registerCommand("buildIndex", new BuildIndexCommand);
  resolver.registerCommand("sequentialSearch", new SequentialSearchCommand);
  resolver.registerCommand("exit", new ExitCommand(&running));

  std::string input;
  while(running) {
    std::cin >> input;
    resolver.execute(input);
  }

  return 0;
}
