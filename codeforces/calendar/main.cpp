#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::string> companies(n);

  int l = 1;
  int s = 10;

  for (size_t i = 0; i < n; i++) {
    std::cin >> companies[i];
    if (companies[i].length() > l)
      l = companies[i].length();
    if (companies[i].length() < s)
      s = companies[i].length();
  }

  std::sort(companies.begin(), companies.end());

  char separator;
  std::cin >> separator;

  std::vector<std::deque<std::string>> grouped(l + 1);
  for (size_t i = 0; i < n; i++) {
    grouped[companies[i].size()].push_back(companies[i]);
  }

  std::vector<std::string> ans;
  
  for (size_t i = s; i <= l; i++) {
    while (!grouped[i].empty()) { 
      std::string a = grouped[i].front();
      grouped[i].pop_front();

      std::string b = grouped[l - i + s].front();
      grouped[l - i + s].pop_front();
  
      std::string first = a + separator + b;
      std::string second = b + separator + a;

      std::string row = first < second ? first : second;
      ans.push_back(row);
    }
  }

  std::sort(ans.begin(), ans.end());
  for(std::string a : ans) std::cout << a << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
