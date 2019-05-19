#include <iostream>
#include <vector>


long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
  long long max_product = 0;
  int n = numbers.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      max_product = std::max(max_product,
			     numbers[i] * numbers[j]);
    }
  }
  return max_product;
}

long long MaxPairwiseProductFast(const std::vector<long long>& numbers) {

  int max1_idx = 0;
  int max2_idx = -1;
  int n = numbers.size();
  for (int i = 1; i < n; i++) {
    if (numbers[i] > numbers[max1_idx]) {
      max1_idx = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if ((max2_idx == -1 || numbers[i] > numbers[max2_idx]) && i != max1_idx) {
      max2_idx = i;
    }
  }

  // std::cout << "!!" << max1_idx << " " << max2_idx << "\n";
  return numbers[max1_idx] * numbers[max2_idx];
}

long long MaxPairwiseProductFast2(const std::vector<long long>& numbers) {

  int max1_idx = -1;
  int max2_idx = -1;
  int n = numbers.size();
  
  for (int i = 0; i < n; i++) {
    // max1_idx is the index of biggest num so far
    if (max1_idx == -1 || numbers[i] > numbers[max1_idx] ) {
      max2_idx = max1_idx;
      max1_idx = i;
    } else if (max2_idx == -1 || numbers[i] > numbers[max2_idx]) {
      max2_idx = i;
    }
    
    // std::cout << "idx1: " << max1_idx << " idx2: " << max2_idx << std::endl;
  }

  // std::cout << "!!" << max1_idx << " " << max2_idx << "\n";
  return numbers[max1_idx] * numbers[max2_idx];
}

int StressTest() {
  int n;
  int max_n = 20;
  int max_num = 1000;
  int result1, result2;

  int iter = 0;
  while (iter++ < 1000000) {
    n = rand() % (max_n - 2) + 2;
    // std::cout << n << "\n";
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
      numbers[i] = rand() % max_num;
      // std::cout << numbers[i] << " ";
    }
    // std::cout << "\n\n";
    result1 = MaxPairwiseProductFast2(numbers);
    result2 = result1; //MaxPairwiseProductFast(numbers);    
    if (result1 != result2) {
      std::cout << "Wrong: " << result1 << " " << result2;
      return 1;
    }
  }
}

int run() {
  int n;
  std::cin >> n;
  std::vector<long long> numbers(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }
  std::cout << MaxPairwiseProductFast2(numbers) << "\n";
  return 0;
}

int main() {
  return StressTest();
}
