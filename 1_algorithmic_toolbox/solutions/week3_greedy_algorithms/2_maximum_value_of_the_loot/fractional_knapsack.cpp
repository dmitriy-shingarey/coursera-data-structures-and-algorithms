/*
Input: Weights w1,...,wn and values
v1,...,vn of n items; capacity W

Output: The maximum total value of
fractions of items that fit into a
bag of capacity W.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, vector<std::pair<double, int>> ratio)
{
  double value = 0.0;

  auto it = ratio.begin();

  while (it != ratio.end())
  {

    if (capacity != 0)
    {
      auto a = std::min(it->second, capacity);
      value = value + (a * it->first);
      it->second = it->second - a;
      capacity = capacity - a;
      if (a == 0)
      {
        it++;
      }
    }
    else
    {
      it++;
    }
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  vector<std::pair<double, int>> ratio;

  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
    ratio.push_back({double(values[i]) / weights[i], weights[i]});
  }

  std::sort(ratio.begin(), ratio.end(), [](const std::pair<double, int> &myPair1, const std::pair<double, int> &myPair2)
            { return myPair2.first < myPair1.first; });

  double optimal_value = get_optimal_value(capacity, weights, values, ratio);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
