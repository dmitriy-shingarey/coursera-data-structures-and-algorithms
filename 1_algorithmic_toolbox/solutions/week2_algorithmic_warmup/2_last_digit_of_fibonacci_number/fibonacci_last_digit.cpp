// #include "../../src/time_estimation.h"
#include <cassert>
#include <iostream>

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

int get_fibonacci_last_digit_fast(int n)
{
    // Get the last digit of x with modulo
    return (n % 10);
}

void test_solution(const int n)
{
    std::cout << "naive: " << get_fibonacci_last_digit_naive(11242) << std::endl;
    std::cout << "fast: " << get_fibonacci_last_digit_fast(11242) << std::endl;

    // assert(get_fibonacci_last_digit_naive(11242) == 6);
    // assert(get_fibonacci_last_digit_fast(11242) == 6);
    // std::cout
    //<< "slow_origin: " << funcTime(get_fibonacci_last_digit_naive, n) << "\n";
    // std::cout << "new_fast   : " << funcTime(get_fibonacci_last_digit_fast, n);
}
int main()
{
    int n;
    std::cin >> n;

    // test_solution(n);
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
