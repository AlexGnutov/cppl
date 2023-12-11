#include <iostream>
#include <exception>
#include <string>
#include <utility>
#include <cstring>

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
    explicit SmartArray(size_t size): data(new int[size]), size(size){
        memset(data, 0, sizeof(int) * size);
        std::cout << "constructor for size: " << size << " called" << std::endl;
    }
    ~SmartArray() {
        delete[] data;
    }

    //! Запрет конструктора копирования.
    SmartArray(const SmartArray&) = delete;

    //! Добавляет элемент в массив.
    void add_element(int value) {
        if (len < size) {
            data[len] = value;
            len++;
        } else {
            throw ArrayError("невозможно добавить элемент: массив переполнен");
        }
    }

    //! Возвращает элемент массива по индексу.
    int get_element(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            throw ArrayError("некорректный индекс: выход за пределы массива");
        }
    }

    //! Выводит значения массива в консоль.
    void print_array() const {
        for (int i = 1; i <= size; ++i) {
            std::cout << data[i-1] << " ";
        }
        std::cout << std::endl;
    }

    //! Создаёт копию массива справа. Исходный массив удаляется.
    SmartArray& operator=(const SmartArray& second) {
        delete[] data;
        len = second.len;
        size = second.size;
        data = new int[second.size];

        for (int i = 0; i < len; ++i) {
            data[i] = second.get_element(i);
        }
        return *this;
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

        std::cout << "Первый массив до присваивания: ";
        arr.print_array();

        SmartArray arr_2(2);
        arr_2.add_element(10);
        arr_2.add_element(11);
        // arr_2.add_element(12);
        // arr_2.add_element(13);
        // arr_2.add_element(14);
        // arr_2.add_element(15);
        // arr_2.add_element(16);

        std::cout << "Второй массив до присваивания: ";
        arr_2.print_array();
        arr = arr_2;

        std::cout << "Первый массив после присваивания: ";
        arr.print_array();


    } catch(const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }


    return 0;
}
