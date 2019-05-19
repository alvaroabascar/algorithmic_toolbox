#include <iostream>
#include <vector>

using namespace std;

long long fibonacci_huge_naive(long long n, long long m) {
  if (n <= 1) {
    return n;
  }

  long long previous = 0;
  long long current = 1;

  for (long long i = 0; i < n - 1; i++) {
    long long tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current) % m;
    //cout << current << endl;
  }
  return current;
}

int periodicity(vector<int> vect, int n) {
  bool is_period;
  if (n < 2) {
    return -1;
  }
  // for (int i = 0; i < n; i++) {
  //   cout << vect[i] << " ";
  // }
  // cout << endl;
  for (int p = 1; p <= n/2; p++) {
    is_period = true;
    for (int offset = 0; offset < p; offset++) {
      if (vect[offset] != vect[offset + p]) {
	is_period = false;
	break;
      }
    }
    if (is_period) {
      //cout << p << " YES" << endl;
      return p;
    }
    // cout << p << " NO" << endl;
  }
  return -1;
}

long long fibonacci_huge(long long n, long long m) {
  if (n <= 1) {
    return n;
  }

  vector<int> vect(10000);
  int period;
  long long previous = 0;
  long long current = 1;
  long long tmp_previous;
  
  vect[0] = 0;
  vect[1] = 1;

  for (long long i = 2; i <= n; i++) {
    tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current) % m;
    vect[i] = current;
    period = periodicity(vect, i);
    // cout << i << " " << current << endl;
    // cout << "found period " << period << endl;
    if (period > 0) {
      // cout << m << " period " << period << endl;
      return vect[n % period];
    }
  }
  return current;
}

int stress() {
  int n, m;
  int max_num = 100000;
  long long r1, r2;
  long niters = 100;
  
  for (int iter = 0; iter < niters; iter++) {
    n = rand();
    n = n % max_num + 3;
    m = rand();
    m = m % (n - 2) + 2;
    r1 = fibonacci_huge_naive(n, m);
    r2 = fibonacci_huge(n, m);
    if (r1 != r2) {
      cout << "WRONG: " << n << " " << m << ": " << r1 << " " << r2 << endl;
    } else {
      cout << "OK!: " << n << " " << m << ": " << r1 << " " << r2 << endl;
    }
  }
}

int main() {
  // stress();
  long long n, m;
  cin >> n >> m;
  // n = 1000000000000000000;
  // m = 1000,
  cout << fibonacci_huge(n, m) << endl;
  return 0;
}
