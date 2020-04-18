class Solution {
    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                {
                    continue;
                }
                
                double c1 = i + 1 < n ? grid[i + 1][j] : 1e6;
                double c2 = j + 1 < m ? grid[i][j + 1] : 1e6;
                
                double minCost = Math.min(c1, c2);
                grid[i][j] += minCost;
            }
        }
        return grid[0][0];
    }
}