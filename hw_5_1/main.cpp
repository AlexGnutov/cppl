#include <vector>
#include <iostream>
#include <algorithm>

//! Шаблонная функция для удаления встречающихся повторно элементов.
template<typename T>
void remove_repeated(std::vector<T>& vec) {
	std::sort(vec.begin(), vec.end(), [](T a, T b) { return a > b; });
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());
}

//! Шаблонная функция для вывода вектора в консоль.
template<typename T>
void print_vec(const std::vector<T>& vec) {
	std::cout << "Vector values: ";
	for (const auto& v : vec) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}


int main() {

	std::vector<int> veni = { 1, 1, 2, 5, 6, 1, 2, 4 };
	std::vector<double> vedi = { 1.2, 1, 2, 1.2, 6, 4, 2, 4 };
	std::vector<char> veci = { 'a', 'c', 'd', 'a', 'b', 'd', 'h', 'c' };

	remove_repeated(veni);
	remove_repeated(vedi);
	remove_repeated(veci);

	print_vec(veni);
	print_vec(vedi);
	print_vec(veci);

}