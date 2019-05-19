#include <iostream>

using namespace std;

int change(int m) {
  int q = 0;
  int n_10, n_5, n_1;
  int rem;
  n_10 = m / 10;
  rem = m % 10;
  n_5 = rem / 5;
  rem = rem % 5;
  n_1 = rem;
  return n_1 + n_5 + n_10;
}

int main() {
  int m;
  cin >> m;
  cout << change(m) << endl;
  return 0;
}
