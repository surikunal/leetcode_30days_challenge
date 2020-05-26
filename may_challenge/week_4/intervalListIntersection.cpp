#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> res;
        int Asize = A.size();
        int Bsize = B.size();
        vector<int> temp(2);
        int Aptr = 0;
        int Bptr = 0;
        while (Aptr < Asize && Bptr < Bsize)
        {
            if (A[Aptr][0] <= B[Bptr][1] && A[Aptr][1] >= B[Bptr][0])
            {
                temp[0] = max(A[Aptr][0], B[Bptr][0]);
                temp[1] = min(A[Aptr][1], B[Bptr][1]);
                res.push_back(temp);
            }
            if (A[Aptr][1] < B[Bptr][1])
                Aptr++;
            else
                Bptr++;
        }
        return res;
    }
};
auto SpeedUp = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();