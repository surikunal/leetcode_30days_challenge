#include <iostream>
#include <vector>
using namespace std;
auto SpeedUp = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};