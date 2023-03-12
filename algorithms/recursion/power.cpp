#include <iostream>

int power(int base, int exp) {
  if (exp == 0)
    return 1;

  int result = power(base, exp / 2);
  result *= result;

  if (exp % 2 != 0)
    result *= base;

  return result;
}

int main() {
  std::cout << power(2, 13);
  return 0;
}