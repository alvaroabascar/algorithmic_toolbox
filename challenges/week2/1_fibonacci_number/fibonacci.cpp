#include <iostream>

using namespace std;

long long fibonacci_naive(int n) {
  if (n <= 1) {
    return static_cast<long long>(n);
  }
  return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_better(int n) {
  long long a = 0;
  long long b = 1;
  long long c;
  int i = 1;
  if (n <= 1) {
    return n;
  }
  while (i++ < n) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

int run() {
  int n;
  cin >> n;
  cout << fibonacci_better(n);
  return 0;
}

int speed_test() {
  cout << fibonacci_better(200);
}

int stress_test() {
  int r1, r2;
  for (int n = 0; n < 45; n++) {
    r1 = fibonacci_naive(n);
    r2 = fibonacci_better(n);
    if (r1 != r2) {
      cout << "wrong " << n << " " << r1 << " " << r2;
    }
  }
}

int main() {
  run();
}
