#include <iostream>
#include <string>

bool is_palindrome(std::string word, int i) {
  if (i > word.length() / 2) {
    return true;
  }

  if (word[i] != word[word.length() - 1 - i]) {
    return false;
  }

  return is_palindrome(word, i + 1);
}

int main() {
  std::string word = "racecar";
  bool ans = is_palindrome(word, 0);
  std::cout << ans;
  return 0;
}