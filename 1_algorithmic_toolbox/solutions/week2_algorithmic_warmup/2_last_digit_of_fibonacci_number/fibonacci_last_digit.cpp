// #include "../../src/time_estimation.h"
#include <cassert>
#include <immintrin.h>
#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fibonacci_fast(int n, std::vector<int> &v)
{

    v[0] = 0;
    v[1] = 1;

    for (size_t i = 2; i < v.size(); i++)
    {
        v[i] = v[i - 1] % 10 + v[i - 2] % 10;
    }

    return v[n];
}

int get_fibonacci_last_digit_fast(int n)
{
    // Get the last digit of x with modulo
    return (n % 10);
}

void test_solution(const int n, const std::vector<int> &v)
{
    std::cout << "naive: " << get_fibonacci_last_digit_naive(n) << std::endl;
    std::cout << "fast: " << get_fibonacci_last_digit_fast(v[n]) << std::endl;

    // std::cout << "slow_origin: " << funcTime(get_fibonacci_last_digit_naive, n) << "\n";
    // std::cout << "new_fast   : " << funcTime(get_fibonacci_last_digit_fast, n) << "\n";

    assert(get_fibonacci_last_digit_naive(10) == 5);
    assert(get_fibonacci_last_digit_fast(v[10]) == 5);

    assert(get_fibonacci_last_digit_naive(3) == 2);
    assert(get_fibonacci_last_digit_fast(v[3]) == 2);
}
int main()
{
    int n;
    std::cin >> n;

    // Find the 10th Fibonacci number as an array
    // const std::vector<int> v = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
    //                            55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229};

    std::vector<int> v;
    v.resize(n + 1, 0);
    fibonacci_fast(n, v);
    // std::cout << "v[n]: " << v[n] << std::endl;

    // test_solution(n, v);
    int c = get_fibonacci_last_digit_fast(v[n]);
    std::cout << c << '\n';
}
