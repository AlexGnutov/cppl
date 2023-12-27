#include <iostream>
#include <vector>

template<typename T>
void square(T& a) {
	a = a * a;
}

template<typename T>
void square(std::vector<T>& v) {
	for (T& a : v) {
		a = a * a;
	}
}

int main() {

	int a = 4;
	std::cout << "[in]: 4" << std::endl;
	square(a);
	std::cout << "[out]: " << a << std::endl;

	std::vector<double> dv = { -1, 4, 8 };
	std::cout << "[in]: -1, 4, 8" << std::endl;

	square(dv);
	std::string sep = "";
	std::cout << "[out]: ";
	for (const auto& a : dv) {
		std::cout << sep << a;
		sep = ", ";
	}

}