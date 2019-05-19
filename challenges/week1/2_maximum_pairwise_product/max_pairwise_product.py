import numpy as np

def max_pairwise_product(numbers):
    idx_max1 = -1
    idx_max2 = -1
    for i, num in enumerate(numbers):
        if idx_max1 == -1 or num > numbers[idx_max1]:
            idx_max2 = idx_max1
            idx_max1 = i
        elif idx_max2 == -1 or num > numbers[idx_max2]:
            idx_max2 = i
    return numbers[idx_max1]*numbers[idx_max2]
        


def main():
    n = int(input())
    nums = list(map(int, input().split()[:n]))
    print(max_pairwise_product(nums))

def stress():
    iters = 1000000
    max_n = 20;
    max_num = 1000;
    
    for i in range(iters):
        n = np.random.randint(max_n - 2) + 2
        nums = np.random.randint(max_num, size=(1, n))
        max_pairwise_product(nums)

if __name__ == '__main__':
    stress()
