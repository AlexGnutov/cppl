#include <iostream>
#include <vector>
#include <algorithm>

//! Функтор для подсчёта чисел, которые делятся без остатка на переданный
//! аргумент конструктора.
class get_count {
	int counter;
	int factor;

public:
	get_count(int factor) : counter(0) {
		if (factor <= 0) {
			throw "factor must be positive";
		}
		this->factor = factor;
	}

	void operator()(int a) {
		if (a % factor == 0) {
			++counter;
		}
	}

	int operator()() { return counter; }
};

//! Функтор для подсчёта суммы чисел, которые делятся без остатка на аргумент
//! конструктора.
class get_sum {
	int sum;
	int factor;

public:
	get_sum(int factor) : sum(0) {
		if (factor <= 0) {
			throw "factor must be positive";
		}
		this->factor = factor;
	}

	void operator()(int a) {
		if (a % factor == 0) {
			sum += a;
		}
	}

	int operator()() { return sum; }
};

int main() {

	std::vector<int> in = { 4, 1, 3, 6, 25, 54 };

	get_count gc(3);
	gc = std::for_each(in.begin(), in.end(), gc);
	std::cout << gc() << std::endl;

	get_sum s(3);
	s = std::for_each(in.begin(), in.end(), s);
	std::cout << s() << std::endl;
}