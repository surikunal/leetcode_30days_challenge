#include <iostream>
#include <vector>
using namespace std;
auto SpeedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int freq = 1, suspect = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (suspect == nums[i])
                freq++;
            else
                freq--;

            if (freq == 0)
            {
                suspect = nums[i];
                freq = 1;
            }
        }

        // as mentions in question that majority element always exist
        // so we dont have to check for the n/2 condition
        // otherwise we have to count using a for loop right here

        return suspect;
    }
};