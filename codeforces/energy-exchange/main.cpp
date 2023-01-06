#include <iostream>

using namespace std;

int n;
int k;

bool solve(double m, double *a) {
  double l = 0;
  double g = 0;

  for (size_t i = 0; i < n; i++) {
    if (a[i] >= m)
      g += a[i] - m;
    else
      l += m - a[i];
  }

  return g - ((g * k)) / 100 >= l;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  double *a = new double[n];
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  double l = 0;
  double r = 1000;

  for (size_t i = 0; i < 1000; i++) {
    double m = (l + r) / 2;

    if (solve(m, a))
      l = m;
    else
      r = m;
  }

  printf("%.9f\n", l);

  return 0;
}
