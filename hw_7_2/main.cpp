#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class BigInt {

public:
	BigInt(const std::string& str) {
		size_ = str.size();
		ptr_ = new int[size_];

		for (int i = 0; i < size_; ++i) {
			ptr_[i] = std::stoi(str.substr(size_ - i - 1, 1));
		}
		std::cout << "constructor called" << std::endl;
	}

	~BigInt() {
		std::cout << "destructor called" << std::endl;
		delete[] ptr_;
	}


	BigInt(const BigInt& other) {

		std::cout << "copy constructor used: " << std::endl;
		size_ = other.size_;
		ptr_ = new int[size_];

		for (int i = 0; i < size_; ++i) {
			ptr_[i] = other.ptr_[i];
		}
	}

	BigInt& operator=(const BigInt& other) {
		if (this == &other) {
			return *this;
		}

		delete[] ptr_;
		size_ = other.size_;
		ptr_ = new int[size_];

		for (int i = 0; i < size_; ++i) {
			ptr_[i] = other.ptr_[i];
		}

		std::cout << "assign operator is used" << std::endl;

		return *this;
	}

	BigInt(BigInt&& other) {
		std::cout << "move constructor used" << std::endl;
		size_ = other.size_;
		ptr_ = other.ptr_;
		other.ptr_ = nullptr;
	}

	BigInt& operator=(BigInt&& other) {
		std::cout << "move assign is used" << std::endl;
		size_ = other.size_;
		std::swap(ptr_, other.ptr_);
		return *this;
	}

	BigInt operator+(const BigInt& other) {

		std::string str = "";

		size_t pos = 0;
		int over = 0;

		while (pos < this->size_ || pos < other.size_) {
			int sum = over;
			if (pos < this->size_) {
				sum += this->ptr_[pos];
			}
			if (pos < other.size_) {
				sum += other.ptr_[pos];
			}
			str.insert(0, 1, std::to_string(sum % 10).c_str()[0]);
			over = sum / 10;
			pos += 1;
		}

		if (over > 0) {
			str.insert(0, 1, std::to_string(over).c_str()[0]);
			pos += 1;
		}
		return BigInt(str);
	}

	BigInt operator*(int multiplier) {

		BigInt acc("0");

		int pos = 0;

		for (int i = 0; i < size_; ++i) {
			int mux = ptr_[i] * multiplier;
			auto str = std::to_string(mux);


			for (int k = 0; k < pos; ++k) {
				str += "0";
			}
			pos += 1;

			std::cout << str << std::endl;
			acc = acc + BigInt(str);
		}


		return acc;
	}

	void print() const {
		for (int i = size_ - 1; i >= 0; --i) {
			std::cout << ptr_[i];
		}
		std::cout << std::endl;
	}

private:
	int* ptr_;
	int size_;
};



int main()
{
	/*
	std::string num_a = "114575";
	std::string num_b = "78524";

	BigInt a(num_a);
	BigInt b(num_b);

	std::cout << "num a: ";
	a.print();
	std::cout << "num b: ";
	b.print();

	std::cout << std::endl;

	{
		std::cout << "1) regular assign is going to be used as far as both values are lvalues" << std::endl;
		BigInt c("0");
		c = a;
		std::cout << "num c: ";
		c.print();
	}
	std::cout << std::endl;

	{
		std::cout << "2) move assign is going to be used as far as (a + b) is rvalue" << std::endl;
		BigInt c("0");
		c = a + b;
		std::cout << "num c: ";
		c.print();
	}
	std::cout << std::endl;

	{
		std::cout << "3) copy constructor is going to be used" << std::endl;
		auto c(a);
		std::cout << "num c: ";
		c.print();
	}
	std::cout << std::endl;

	{
		std::cout << "4) move constructor is going to be used" << std::endl;
		auto c(std::move(a + b));
		std::cout << "num c: ";
		c.print();
	}
	std::cout << std::endl;
	*/

	{
		BigInt a("111");
		int b = 18;

		auto c = a * b;
		std::cout << "result: ";
		c.print();
	}




	return 0;
}