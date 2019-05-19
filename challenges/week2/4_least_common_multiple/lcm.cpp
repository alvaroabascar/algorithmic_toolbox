#include <iostream>

using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; l++) {
    if (l % a == 0 && l % b == 0) {
      return l;
    }
  }
  return (long long) a * b;
}

long long gcd(int a, int b) {
  int c;
  if (a == 0) {
    return b;
  } else if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

long long lcm(int a, int b) {
  return (long long)a*b / gcd(a, b);
}

int stress() {
  int a, b;
  int max_num = 10000;
  long long r1, r2;
  long niters = 1000;
  
  for (int iter = 0; iter < niters; iter++) {
    a = rand() % max_num;
    b = rand() % max_num;
    r1 = lcm_naive(a, b);
    r2 = r1; //lcm_naive(a, b);
    if (r1 != r2) {
      cout << "WRONG: " << a << " " << b << ": " << r1 << " " << r2 << endl;
    } else {
      cout << "OK: " << a << " " << b << endl;
    }
  }
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
  return 0;
}
  
