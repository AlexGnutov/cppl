#include <iostream>
#include <vector>

template<typename T>
T square(T a) {
	return a * a;
}

template<typename T>
void square(std::vector<T> &v) {
	for (T &a : v) {
		a = a * a;
	}
}

int main() {

	std::cout << "[in]: 4" << std::endl;
	std::cout << "[out]: " << square(4) << std::endl;

	std::vector<double> dv = {-1, 4, 8};
	std::cout << "[in]: -1, 4, 8" << std::endl;

	square(dv);
	std::string sep = "";
	std::cout << "[out]: ";
	for (const auto& a : dv) {
		std::cout << sep << a;
		sep = ", ";
	}
	
}