#include <iostream>
#include <string>
#include <sstream>

std::string splitString(char splitter, std::string input, int iterations) {
	std::istringstream iss(input);
	std::string token;

	for (int i = 0; i < iterations; i++) {
		std::getline(iss, token, splitter);
	}

	return token;
}

int main() {

	std::cout << splitString('-', "1-2-3-4-5-6", 3);

	return 0;

}
