#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);
        int offset = 1;
        for (int i = 1; i < num + 1; i++)
        {
            if (offset * 2 == i)
                offset *= 2;
            ans[i] = ans[i - offset] + 1;
        }
        return ans;
    }
};
auto SpeedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();

///==============================================

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans;
        for (int i = 0; i <= num; i++)
        {
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};
auto SpeedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();