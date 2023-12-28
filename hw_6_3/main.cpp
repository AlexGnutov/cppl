#include <iostream>
#include <vector>
#include <memory>
#include <string>

template<typename T>
class my_u_ptr {

public:
	my_u_ptr(T* ptr) : ptr(ptr) {}
	~my_u_ptr() {
		delete ptr;
	}

	my_u_ptr(const my_u_ptr&) = delete;
	void operator=(const my_u_ptr&) = delete;

	T operator*() {
		return *ptr;
	}

	T* operator->() const {
		return ptr;
	}

	T* release() {
		auto tmp = ptr;
		ptr = nullptr;
		return tmp;
	}

private:
	T* ptr = nullptr;
};

class BookShelf {
public:
	BookShelf(std::string color, int weight) : color(color), weight(weight) {}
	std::string color;
	int weight;
};

int main()
{
	my_u_ptr<BookShelf> ptr(new BookShelf("red", 100));

	auto bs = *ptr;
	std::cout << bs.color << " " << bs.weight << std::endl;
	std::cout << ptr->color << " " << ptr->weight << std::endl;


	return 0;
}