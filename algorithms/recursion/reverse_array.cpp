#include <iostream>

void print(int array[], int n) {
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << array[i] << ' ';
  }
  std::cout << "]\n";
}

void reverse(int array[], int low, int high) {
  if (low < high) {
    int tmp = array[low];
    array[low] = array[high];
    array[high] = tmp;
    reverse(array, low + 1, high - 1);
  }
}

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  print(array, 10);
  reverse(array, 0, 9);
  print(array, 10);

  return 0;
}