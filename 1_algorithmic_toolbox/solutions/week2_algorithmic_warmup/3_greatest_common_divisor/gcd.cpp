// #include "../../src/time_estimation.h"
#include <cassert>
#include <iostream>

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

// euclead
int gcd_fast(int a, int b)
{
  if (b == 0)
  {
    return a;
  }
  else
  {
    return gcd_fast(b, a % b);
  }
}

// void test_solution(const int a, const int b)
//{
//   assert(gcd_naive(461952, 116298) == 18);
//   assert(gcd_fast(461952, 116298) == 18);
//   std::cout << "slow_origin: " << funcTime(gcd_naive, a, b) << "\n";
//   std::cout << "new_fast   : " << funcTime(gcd_fast, a, b);
// }

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  // test_solution(a, b);
  return 0;
}
