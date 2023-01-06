#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Tiger {
  int size;
  double min_size_to_eat;

  Tiger(int size, double min_size_to_eat)
      : size(size), min_size_to_eat(min_size_to_eat) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<Tiger *> tigers;

  double r;
  int k;

  for (int i = 0; i < n; i++) {
    cin >> r >> k;
    tigers.push_back(new Tiger(r, r / k));
  }

  sort(begin(tigers), end(tigers), [](const Tiger *lhs, const Tiger *rhs) {
    return lhs->size < rhs->size;
  });

  Tiger *last = tigers[0];
  int ans = 1;

  for (int i = 1; i < tigers.size(); i++) {
    if (tigers[i]->min_size_to_eat >= last->size) {
      ans++;
      last = tigers[i];
    }
  }

  cout << ans;
}
