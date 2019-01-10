#include "ExitCommand.h"

ExitCommand::ExitCommand(bool *running)
  : running_(running) { }

void ExitCommand::execute() {
  *running_ = false;
}
