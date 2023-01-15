/*
Input: A car which can travel at most "m"
kilometers with full tank, a source
point A, a destination point B and
n gas stations at distances
x1 ≤x2 ≤x3 ≤···≤xn in
kilometers from A along the path
from A to B.

Output: The minimum number of refills to
get from A to B , besides refill at A.
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int location, int dist, int tank, vector<int> &stops)
{
    if (location + tank >= dist)
    {
        return 0;
    }

    auto it_next_stop = stops.begin();
    if (it_next_stop == stops.end() || (*it_next_stop - location) > tank)
    {
        return -1;
    }
    while (it_next_stop != stops.end() && (*it_next_stop - location) <= tank)
    {
        it_next_stop++;
    }
    vector<int> new_stops_(it_next_stop, stops.end());
    auto ret = compute_min_refills(*--it_next_stop, dist, tank, new_stops_);
    if (ret < 0)
    {
        return -1;
    }
    else
    {
        return 1 + ret;
    }
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(0, d, m, stops) << "\n";

    return 0;
}