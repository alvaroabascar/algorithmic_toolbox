#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else if (a == 0) {
    return b;
  }
  for (long long i = min(a, b); i > 0; i--) {
    if (a % i == 0 && b % i == 0) {
      return i;
    }
  }
}

long long gcd_euclid(long long a, long long b) {
  if (b == 0) {
    return a;
  } else if (a == 0) {
    return b;
  }
  return gcd_euclid(b, a % b);
}

int run() {
  long long a, b;
  cin >> a;
  cin >> b;
  cout << gcd_euclid(a, b);
}

int stress_test() {
  int max_num = 1000000;
  long long a, b, r1, r2;
  int i, num_iters = 1000000000;
  srand(42);
  while (i++ < num_iters) {
    a = rand() % max_num;
    b = rand() % max_num;
    r1 = gcd(a, b);
    r2 = gcd_euclid(a, b);
    if (r1 != r2) {
      cout << "Wrong: " << r1 << " " << r2 << " for " << a << " " << b << endl;
      return 1;
    }
  }
}

int main() {
  run();
  return 0;
}
