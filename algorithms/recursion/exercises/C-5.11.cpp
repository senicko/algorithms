#include <iostream>

int log_base_2(int n, int curr) {
  // Check if n is valid
  if (n < 1) {
    return -1;
  }

  if (n == 1) {
    return curr;
  }

  return log_base_2(n / 2, curr + 1);
}

int main() {
  int log = log_base_2(9, 0);
  std::cout << log << std::endl;
  return 0;
}