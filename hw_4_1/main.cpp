#include <iostream>
#include <map>
#include <string>

int main() {

	std::string str = "";

	std::cout << "[in]: ";
	getline(std::cin, str);
	std::cout << std::endl;

	std::map<char, int> characters{};

	for (const char& ch : str) {
		if (characters.count(ch) == 0) {
			characters[ch] = 1;
		}
		else {
			characters[ch] = characters[ch] + 1;
		}
	}

	std::multimap<int, char> sorted{};

	for (auto& pair : characters) {
		int key = static_cast<int>(pair.second);
		sorted.insert({ pair.second, pair.first });
	}

	std::cout << "[out]:" << std::endl;

	for (auto i = sorted.rbegin(); i != sorted.rend(); ++i) {
		std::cout << (*i).second << ": " << (*i).first << std::endl;
	}

	return 0;
}