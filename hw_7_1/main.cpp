#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T>& a, std::vector<T>& b) {
	auto tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

template<typename T>
void print_vector(std::vector<T>& vec) {
	std::cout << "{ ";
	for (const auto& v : vec) {
		std::cout << v << " ";
	}
	std::cout << "}" << std::endl;
}


int main()
{

	std::vector<int> a = { 0,1,2,3,4,5 };
	std::vector<int> b = { 9,8,7,6 };

	print_vector(a);
	print_vector(b);

	move_vectors(a, b);

	print_vector(a);
	print_vector(b);

	return 0;
}