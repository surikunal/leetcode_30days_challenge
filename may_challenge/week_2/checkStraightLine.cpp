#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        double num = (float)(arr[1][1]-arr[0][1]);
        double denum = (float)(arr[1][0]-arr[0][0]);
        double m = (num/denum);
        for (int i = 2; i < arr.size(); i++)
        {
            double slope = ((double)(arr[i][1]-arr[i-1][1])/(double)(arr[i][0]-arr[i-1][0]));
            if (slope != m)
                return false;
        }
        return true;
    }
};