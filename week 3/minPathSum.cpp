#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                continue;
            }

            int c1 = i + 1 < n ? grid[i + 1][j] : 1e6;
            int c2 = j + 1 < m ? grid[i][j + 1] : 1e6;

            int minCost = min(c1, c2);
            grid[i][j] += minCost;
        }
    }
    return grid[0][0];
}

int main(int args, char **argv)
{
    vector<vector<int>> arr = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    minPathSum(arr);
    return 0;
}