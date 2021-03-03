#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int distributeCandies(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int count = 1;
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] != arr[i - 1])
            {
                count++;
            }
        }
        return count <= arr.size() / 2 ? count : arr.size() / 2;
    }
};