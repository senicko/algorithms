#include <cmath>
#include <iostream>
using namespace std;

long long qpow(long long base, long long power) {
  if (power == 0)
    return 1;

  if (power % 2 == 0) {
    long long r = qpow(base, power / 2);
    return (r * r) % 998244353;
  }

  return (base * qpow(base, power - 1)) % 998244353;
}

void solve() {
  long long w, h;
  cin >> w >> h;
  cout << qpow(2, w + h);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}