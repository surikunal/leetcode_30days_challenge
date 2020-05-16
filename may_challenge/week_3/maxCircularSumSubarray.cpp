#include <iostream>
#include <vector>
#include <climits>
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
    int kadans(int i, int j, vector<int> &arr, int sign)
    {
        int ans = INT_MIN;
        int curr = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            curr = (sign * arr[k]) + max(0, curr);
            ans = max(curr, ans);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int> &A)
    {
        if (A.size() == 1)
            return A[0];
        int S = 0;
        for (int i : A)
            S += i;
        int ans1 = kadans(0, A.size() - 1, A, 1);
        int ans2 = S + kadans(1, A.size() - 1, A, -1);
        int ans3 = S + kadans(0, A.size() - 2, A, -1);
        return max(ans1, max(ans2, ans3));
    }
};