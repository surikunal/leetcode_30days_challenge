#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        if (N == 0 || N == 1)
            return N;
        vector<int> arr(N + 1, 0);
        for (auto &t : trust)
            arr[t[1]]++, arr[t[0]]--;
        for (int i = 0; i <= N; i++)
            if (arr[i] == N - 1)
                return i;
        return -1;
    }
};