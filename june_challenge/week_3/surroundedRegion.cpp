#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void surroundedRegion_DFS(int r, int c, int n, int m, vector<vector<char>> &board)
    {
        if (board[r][c] != 'O')
            return;

        board[r][c] = '#';
        if (r + 1 < n)
            surroundedRegion_DFS(r + 1, c, n, m, board);
        if (r - 1 >= 0)
            surroundedRegion_DFS(r - 1, c, n, m, board);
        if (c + 1 < m)
            surroundedRegion_DFS(r, c + 1, n, m, board);
        if (c - 1 >= 0)
            surroundedRegion_DFS(r, c - 1, n, m, board);
    }

    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;

        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                surroundedRegion_DFS(i, 0, n, m, board);
            }
            if (board[i][m - 1] == 'O')
            {
                surroundedRegion_DFS(i, m - 1, n, m, board);
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
            {
                surroundedRegion_DFS(0, j, n, m, board);
            }
            if (board[n - 1][j] == 'O')
            {
                surroundedRegion_DFS(n - 1, j, n, m, board);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '#') // not surrounded region
                    board[i][j] = 'O';
                else if (board[i][j] == 'O') //surrounded region
                    board[i][j] = 'X';
            }
        }
    }
};