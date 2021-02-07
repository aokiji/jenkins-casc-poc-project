#include "utils/greetings.h"
#include <iostream>

void utils::greet(utils::GreetingType type) {
  std::string message;
  if (type == utils::GreetingType::Hello) {
    message = "Hello World!";
  }
  else if (type == utils::GreetingType::GoodBye) {
    message = "Good Bye!";
  }
  else {
    message = "Ackward salute!";
  }

  std::cout << message << std::endl;
}
