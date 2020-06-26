class Solution {
    public int numTrees(int n) {
        return catalan_num(n);
    }

    public int catalan_num(int n) {
        if (n == 0 || n == 1)
            return 1;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - j - 1];
        return dp[n];
    }
}