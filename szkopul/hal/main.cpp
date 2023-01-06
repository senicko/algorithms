#include <iostream>
using namespace std;

void solve() {
  int t;
  int n;
  cin >> t >> n;

  int *houses = new int[n];

  for (int i = 0; i < n; i++)
    cin >> houses[i];

  int *pref = new int[n + 1];
  pref[0] = 0;

  for (size_t i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + houses[i - 1];
  }

  int x;
  int y;

  for (int i = 0; i < t; i++) {
    cin >> x >> y;
    cout << pref[y] - pref[x - 1] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
