#include <iostream>
#include <string>

#include "CommandResolver.h"
#include "DeleteCommand.h"
#include "UpdateCommand.h"
#include "SequentialSearchCommand.h"
#include "ExitCommand.h"

int main() {
  bool running = true;

  CommandResolver resolver;
  resolver.registerCommand("update", new UpdateCommand);
  resolver.registerCommand("delete", new DeleteCommand);
  resolver.registerCommand("sequentialSearch", new SequentialSearchCommand);
  resolver.registerCommand("exit", new ExitCommand(&running));

  std::string input;
  while(running) {
    std::cin >> input;
    resolver.execute(input);
  }

  return 0;
}
