#include <iostream>
#include <fstream>
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
	//std::ifstream file;
	//file.open("cfg.txt");
/*
	std::ifstream file("cfg.txt");
	std::string content;
	if (!file) { return 1; }
	while (file.good()) {
		file >> content;
		std::cout << content << std::endl;
	}*/



	std::ifstream file("cfg.txt");
	std::string content;
	if (!file) { return 1; }

	char storageChar;
	while (file) {
		storageChar = file.get();
		content += storageChar;
	}

	// Format final version
	content = content.substr(0, content.size() - 2);

	std::cout << content << std::endl;

	// Get phone name
	
	std::string phoneName = splitString(
			':',
			splitString('\n', content, 1),
			2
		   );

	std::cout << "Phone name: " << phoneName << std::endl;

	// Get theme
	std::string theme = splitString(
			':',
			splitString('\n', content, 2),
			2
		   );

	std::cout << "User theme color: " << theme << std::endl;

	return 0;
}
