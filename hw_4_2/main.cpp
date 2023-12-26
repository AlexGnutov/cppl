#include <iostream>
#include <set>
#include <string>

int main() {

	int count = 0;

	std::cout << "[in]: " << std::endl;
	std::cin >> count;

	std::set<int> s{};

	for (int i = 0; i < count; ++i) {
		int current = 0;
		std::cin >> current;
		s.insert(current);
	}

	std::cout << "[out]: " << std::endl;

	for (auto i = s.rbegin(); i != s.rend(); ++i) {
		std::cout << (*i) << std::endl;
	}

	return 0;
}