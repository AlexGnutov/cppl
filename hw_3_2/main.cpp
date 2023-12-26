#include <iostream>

template <class T> class table {
public:
  table(int r, int c) : rows(r), cols(c) {
    data = new T *[rows];
    for (int i = 0; i < rows; i++) {
      data[i] = new T[cols];
    }
  }

  ~table() {
    for (int i = 0; i < rows; i++) {
      delete[] data[i];
    }
    delete[] data;
  }

  table<T>(const table<T> &) = delete;
  table<T> &operator=(const table<T> &) = delete;

  int size() const { return rows * cols; }

  T *operator[](int i) const { return data[i]; }
  T *operator[](int i) { return data[i]; }

private:
  T **data = nullptr;
  int rows = 0;
  int cols = 0;
};

int main() {

  table<int> tb(2, 3);
  tb[0][0] = 4;
  std::cout << tb[0][0] << std::endl;
}