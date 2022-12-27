#include <algorithm>
#include <iostream>
#include <vector>

// #include "../../src/time_estimation.h"
#include <cassert>
#include <utility>

long long MaxPairwiseProductSlow(const std::vector<int> &numbers)
{
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = std::max(max_product,
                                   numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProduct(const std::vector<int> &numbers)
{
    int max_product = 0;
    int n = numbers.size();

    /*for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = std::max(max_product,
                                   numbers[first] * numbers[second]);
        }
    }*/

    int idx1{-1};
    int idx2{-1};

    for (size_t i = 0; i < n; i++)
    {
        if ((idx1 == -1) || (numbers[i] > numbers[idx1]))
        {
            idx1 = i;
        }
    }

    for (size_t j = 0; j < n; j++)
    {
        if ((idx1 == -1) || ((numbers[j] > numbers[idx2]) && (j != idx1)))
        {
            idx2 = j;
        }
    }

    return ((long long)numbers[idx1]) * numbers[idx2];
}

int main()
{
    /*
    // TESTS
    // TEST LOGIC
    std::vector<int> numbers1 = {1, 2, 3, 4, 5};
    assert(MaxPairwiseProduct(numbers1) == 20);

    // TEST TIME EXECUTION
    int n = rand() % 1000 + 2;
    std::vector<int> numbers;
    for (size_t i = 0; i < n; i++)
    {
        int x = rand() % 10000;
        numbers.push_back(x);
    }

    // std::cout << "slow_origin: " << funcTime(MaxPairwiseProductSlow, numbers) << "\n";
    // std::cout << "new_fast   : " << funcTime(MaxPairwiseProduct, numbers);

    */

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }
    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
