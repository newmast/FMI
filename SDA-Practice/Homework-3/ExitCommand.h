#pragma once
#include "ICommand.h"

/*
 * Command that is responsible for exiting the main loop.
 */
class ExitCommand : public ICommand {
  bool *running_;
public:
  ExitCommand(bool *running);
  virtual void execute();
};
