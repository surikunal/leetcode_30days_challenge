#include <iostream>
#include <vector>
using namespace std;
auto SpeedUp = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution
{
    vector<int> w_sum;
    int sum;

public:
    Solution(vector<int> &w)
    {
        sum = 0;
        for (int i : w)
        {
            sum += i;
            w_sum.push_back(sum);
        }
    }

    int pickIndex()
    {
        int idx = rand() % sum;
        return binarySearch(idx + 1);
    }

    int binarySearch(int val)
    {
        int l = 0;
        int r = w_sum.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (w_sum[mid] < val)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};