#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int findMaxLength(vector<int> &arr)
    {
        unordered_map<int, int> map;

        int sum = 0, longestSubarray = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 1)
                sum += 1;
            else
                sum += -1;

            if (sum == 0)
            {
                if (longestSubarray < i + 1)
                {
                    longestSubarray = i + 1;
                }
            }
            else if (map.find(sum) != map.end())
            {
                if (longestSubarray < i - map[sum])
                {
                    longestSubarray = i - map[sum];
                }
            }
            else
            {
                map[sum] = i;
            }
        }
        return longestSubarray;
    }
};