#include "vector.h"
#include <stdlib.h>

// Reads vector_count vectors from the input stream and sums them.
void plus(int vector_count)
{
  Vector3D total;
  Vector3D current;
  while(vector_count-- > 0) {
    std::cin >> current;
    total = total + current;
  }

  std::cout << total << std::endl;
}

// Reads vector_count vectors from the input stream and subtracts them from the first one.
void minus(int vector_count)
{
  Vector3D total;
  Vector3D current;
  std::cin >> total;
  while(vector_count-- > 1) {
    std::cin >> current;
    total = total - current;
  }

  std::cout << total << std::endl;
}

// Reads vector_count vectors from the input stream and prints the negative of each one.
void neg(int vector_count)
{
  Vector3D current;

  std::cin >> current;
  std::cout << -current;

  while(vector_count-- > 1) {
    std::cin >> current;
    std::cout << " " << -current;
  }
}

// Reads vector_count vectors from the input stream and prints each one scaled by a factor.
void pre_num(const char *number_string, int vector_count)
{
  int number = atoi(number_string);
  Vector3D current;
  std::cin >> current;
  std::cout << current * number;
  while(vector_count-- > 1) {
    std::cin >> current;
    std::cout << " " << current * number;
  }
}

// Reads vector_count vectors from the input stream and prints each one scaled by a factor.
void post_num(const char *number_string, int vector_count)
{
  int number = atoi(number_string);
  Vector3D current;
  std::cin >> current;
  std::cout << number * current;
  while(vector_count-- > 1) {
    std::cin >> current;
    std::cout << " " << number * current;
  }
}

int main()
{
  int vector_count = 0;
  std::string command;
  std::cin >> command >> vector_count;

  if (command == "+") {
    plus(vector_count);
  } else if (command == "-") {
    minus(vector_count);
  } else if (command == "NEG") {
    neg(vector_count);
  } else if (command[0] == '*') {
    pre_num(command.c_str() + 1, vector_count);
  } else if (*command.rbegin() == '*') {
    post_num(command.substr(0, command.length() - 1).c_str(), vector_count);
  }

  return 0;
}
