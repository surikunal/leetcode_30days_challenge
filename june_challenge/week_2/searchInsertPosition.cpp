#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int l = 0, h = nums.size() - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l;
    }
};