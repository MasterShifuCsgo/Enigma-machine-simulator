#include "engima_machine.h"
#include <memory>
#include <string>
#include <iostream>

using namespace EnigmaMachine;
using namespace EnigmaMachine::_internal;

#if (DEBUG) || (_DEBUG)
static inline void log(std::string message) {
	std::cout << message << std::endl;
}
#else
static inline void log(std::string message) {
}
#endif

const unsigned int Rotor::getSeed() {
  return seed;
}
const std::unordered_map<char, char> Rotor::getLinks() {
  return links;
}

Machine::Machine()
{
	//create amount_of_rotors amount of seeds.
	for (int i = 0; i <= amount_of_rotors; i++) {
		std::random_device rd; //random seed creator.
		std::mt19937 rng(rd());

		std::uniform_int_distribution<int> dist;

		unsigned int seed = dist(rng);
		std::unique_ptr<Rotor> r = std::make_unique<EnigmaMachine::_internal::Rotor>(seed);
		rotors.push_back(std::move(r));
	}
}

void Machine::setAmountOfRotors(int num) {
	amount_of_rotors = num;
};
int Machine::getAmountOfRotors() {
	return amount_of_rotors;
};

std::string Machine::start(std::string user_input) {

		std::string result;
		std::string temp;
		for (int i = 0; i < rotors.size(); i++) {
			for (int j = 0; j < user_input.size(); j++) {				
				auto links = rotors[i]->getLinks();								
				std::cout << links.at(user_input[j]);
				temp += links.at(user_input[j]);	//adds letter to the temp							
			}
			std::cout << '\n';
			result = temp;
			temp = "";
		}

		return result;
};