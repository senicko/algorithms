#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int n;
int *h;

bool check(int m) {
  int count = 0, coverage = 0;

  for (size_t i = 0; i < n; i++) {
    if (h[i] > coverage) {
      coverage = m + h[i];
      count++;
    }
  }

  return count > 3;
}

int solve() {
  int l = 0, r = 1e9;

  while (l < r) {
    int m = (l + r) / 2;
    if (check(m))
      l = m + 1;
    else
      r = m;
  }

  return l;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  h = new int[n];
  for (size_t i = 0; i < n; i++)
    cin >> h[i];
  sort(h, h + n);

  int ans = solve();
  cout << setprecision(9) << fixed << ans / 2.0 << '\n';
  
  int count = 0, coverage = 0;

  for(size_t i = 0; i < n; i++) {
    if(h[i] > coverage) {
      coverage = h[i] + ans;
      count++;
      cout << setprecision(9) << fixed << h[i] + ans / 2.0 << ' ';
    }
  }

  while(count < 3) {
    cout << 0 << ' ';
    count++;
  }

  return 0;
}
