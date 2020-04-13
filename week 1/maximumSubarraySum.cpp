#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int imax = 0;
        int omax = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            if (imax < 0)
            {
                imax = arr[i];
            }
            else 
            {
                imax += arr[i];            
            }
            
            if (imax > omax)
            {
                omax = imax;
            }
        }
        return omax;
    }
};