#include <iostream>

using namespace std;

long long fibonacci(int n) {
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

int fibonacci_last_digit(int n) {
  int a = 0;
  int b = 1;
  int c;
  int i = 1;
  if (n <= 1) {
    return n;
  }
  while (i++ < n) {
    c = (a + b) % 10;
    a = b;
    b = c;
  }
  return b;
}

int speed_test() {
  cout << fibonacci_last_digit(2001);
}

int stress_test() {
  int r1, r2;
  for (int n = 0; n < 45; n++) {
    r1 = fibonacci_last_digit(n);
    r2 = fibonacci(n) % 10;
    if (r1 != r2) {
      cout << "wrong " << n << " " << r1 << " " << r2 << endl;;
    } else {
      cout << n << " OK" << "\n";
    }
  }
}

int main() {
  long long n;
  cin >> n;
  cout << fibonacci_last_digit(n);
}
