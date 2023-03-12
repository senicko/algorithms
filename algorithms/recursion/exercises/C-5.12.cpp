#include <iostream>

bool is_unique(int array[], int n, int idx = 0) {
  if (idx == n) {
    return true;
  }

  for (int i = 0; i < n; i++) {
    if (i != idx && array[idx] == array[i]) {
      return false;
    }
  }

  return is_unique(array, n, idx + 1);
}

int main() {
  int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  bool unique = is_unique(array, 10);
  std::cout << unique << std::endl;
  return 0;
}