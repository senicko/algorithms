#include <iostream>
using namespace std;

void solve() {
  int recipies[200001];
  int pref[200001];

  for (int i = 0; i < 200001; i++)
    recipies[i] = pref[i] = 0;

  int n, k, q, l, r;
  cin >> n >> k >> q;

  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    recipies[l]++;
    recipies[r + 1]--;
  }

  for (int i = 1; i < 200001; i++) {
    recipies[i] += recipies[i - 1];
    if (recipies[i] >= k)
      pref[i]++;
  }

  for (int i = 1; i < 200001; i++) {
    pref[i] += pref[i - 1];
  }

  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
