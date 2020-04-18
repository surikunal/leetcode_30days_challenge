#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void DFS(vector<vector<char>> &arr, int i, int j)
    {
        if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == '0')
            return;
        arr[i][j] = '0';
        DFS(arr, i + 1, j);
        DFS(arr, i - 1, j);
        DFS(arr, i, j + 1);
        DFS(arr, i, j - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }
};