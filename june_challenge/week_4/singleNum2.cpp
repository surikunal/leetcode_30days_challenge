#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        int x, sum;
        // Iterate through every bit
        for (int i = 0; i < 32; i++)
        {
            // Find sum of set bits at ith position in all
            // array elements
            sum = 0;
            x = (1 << i);
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] & x)
                    sum++; // counting num of bits...so it should be multiple of 3 for all numbers which are repeating thrice

                // if (!sum % 3) // only true for sum = 1 and 2 (and sum will never be 2)
                // when sum is not multiple of 3 then it means the num is appearing only once so we ON all its bits which make it that num
            }
            result = result | ((sum % 3) << i);
        }
        return result;
    }
};