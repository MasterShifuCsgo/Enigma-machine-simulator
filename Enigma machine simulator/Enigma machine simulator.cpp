
#include <iostream>

#include "engima_machine.h"
#include <string>
#include <iostream>

//makes uppercase letters lowercase and removes spaces.
std::string userInputFilter(std::string s) {
  s.erase(std::remove(s.begin(), s.end(), ' '), s.end()); //removes spaces
  std::transform(s.begin(), s.end(), s.begin(), ::tolower); // changes uppercase chars to lowercase
  return s;
}

int main()
{
    std::cout << "Engima Simulator\n";

    //There are only lowercase characters and no spaces.



    EnigmaMachine::Machine Engima;
    std::string user_input = "hello kaIAUHWFIpar";    
    std::string x = userInputFilter(user_input);
    std::cout << x;

    std::string result = Engima.start(x);
    

    std::cout << result;

}
