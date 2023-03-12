#include <iostream>

/// Finds maximum value in the array.
/// Time complexity O(n) (we 'iterate' through the array).
/// Space complexity O(n) (because of recursion).
int find_max(int array[], int n, int max) {
  if (n == 0) {
    return std::max(array[n], max);
  }
  return find_max(array, n - 1, std::max(array[n], max));
}

int main() {
  int array[10] = {0, 1, 2, 3000, 4, 5, 6, 7, 8, 9};
  int max = find_max(array, 9, array[0]);
  std::cout << max << std::endl;
  return 0;
}