#pragma once
#include <unordered_map>
#include <vector>
#include <random>
#include <string>
#include <iostream>
inline const std::vector<char> alphabet = []() {
	std::vector<char> alph;
	for (char c = 'a'; c <= 'z'; c++) {
		alph.push_back(c);
	}
	return alph;
	}();

namespace EnigmaMachine {
	namespace _internal {
		class Rotor
		{
		public:

			Rotor(unsigned int seed_param) : seed(seed_param)
			{
				std::mt19937 rng(seed); // sets the known seed.
				//logic that would insert random letter pairs with a known seed.

				std::uniform_int_distribution<int> dist('a', 'z');

				for (char c : alphabet) {
					//randomize a number to get a random letter.				
					char random_letter = static_cast<char>(dist(rng));
					//set the randomized pair
					links[c] = random_letter; // 26 alphabet letters					
				}
			};

			const unsigned int getSeed();
			const std::unordered_map<char, char> getLinks();
		private:

			unsigned int seed;

			//predictable random map pattern.
			std::unordered_map<char, char> links;
		};
	}

	class Machine
	{
	public:
		Machine();

		void setAmountOfRotors(int num);
		int getAmountOfRotors();

		std::string start(std::string user_input);

	private:
		int amount_of_rotors = 10;
		std::vector<std::unique_ptr<EnigmaMachine::_internal::Rotor>> rotors;
	};



}






