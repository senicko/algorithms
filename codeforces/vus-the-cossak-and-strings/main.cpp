#include <iostream>
#include <string>
using namespace std;

int count_ones(string s, int l, int r) {
  int c = 0;
  for (int i = l; i <= r; i++)
    if (s.at(i) == '1')
      c++;
  return c;
}

void solve() {
  string a;
  string b;
  cin >> a >> b;

  int bo = count_ones(b, 0, b.size() - 1) % 2;

  // prefix sum to know count of ones on range [a, b] in O(1)
  int *pref = new int[a.size() + 1];
  pref[0] = 0;

  for (int i = 1; i <= a.size(); i++) {
    if (a.at(i - 1) == '1')
      pref[i] = pref[i - 1] + 1;
    else
      pref[i] = pref[i - 1];
  }

  // process
  int l = 1;
  int r = b.size();
  int ans = 0;

  while (r <= a.size()) {
    if (bo == (pref[r] - pref[l - 1]) % 2)
      ans++;
    l++;
    r++;
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}