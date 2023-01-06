#include <iostream>

using namespace std;

void solve() {
  int k;
  int n;
  int a;
  int b;

  cin >> k >> n >> a >> b;

  long long ans = -1;
  int s = 0;
  int e = n;
  long long m;

  while (s <= e) {
    m = (s + e) / 2;

    if ((m * a) + ((n - m) * b) < k) {
      ans = m;
      s = m + 1;
    } else
      e = m - 1;
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int q = 1;
  cin >> q;
  while (q--)
    solve();

  return 0;
}
