#include "CommandResolver.h"

CommandResolver::~CommandResolver() {
  for(std::map<std::string, ICommand*>::iterator itr = resolver.begin(); itr != resolver.end(); itr++)
  {
      delete itr->second;
  }

  resolver.clear();
}

void CommandResolver::registerCommand(std::string name, ICommand *command) {
  resolver[name] = command;
}

void CommandResolver::execute(std::string command) {
  if (resolver[command] == NULL) {
    std::cerr << "Invalid command" << std::endl;
    return;
  }

  resolver[command]->execute();
}
