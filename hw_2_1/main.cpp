#include <iostream>
#include <exception>
#include <string>
#include <utility>

class ArrayError: public std::exception {
public:
    explicit ArrayError(std::string message): message(std::move(message)) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    std::string message;
};

class SmartArray {
public:
    explicit SmartArray(size_t size): data(new int[size]), size(size){}
    ~SmartArray() {
        delete[] data;
    }

    SmartArray(const SmartArray&) = delete;

    void add_element(int value) {
        if (len < size) {
            data[len] = value;
            len++;
        } else {
            throw ArrayError("невозможно добавить элемент: массив переполнен");
        }
    }

    int get_element(int index) const {
        if (index >= 0 && index < len) {
            return data[index];
        } else {
            throw ArrayError("некорректный индекс: выход за пределы массива");
        }
    }

    void print_array() const {
        for (int i = 1; i <= size; ++i) {
            std::cout << data[i-1] << " ";
        }
        std::cout << std::endl;
    }

    int *data = nullptr;
    size_t size = 0;
    size_t len = 0;
};

int main() {

    try {
        SmartArray arr(5);
        arr.add_element(1);
        arr.add_element(2);
        arr.add_element(3);
        arr.add_element(4);
        arr.add_element(5);
        arr.print_array();

        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(4) << std::endl;

        // arr.add_element(15);
        // arr.get_element(5);

    } catch(const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }


    return 0;
}
