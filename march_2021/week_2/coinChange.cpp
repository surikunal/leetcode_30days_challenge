class Solution {
public:
    int coinChange(vector<int>& arr, int tar) {
        if (arr.size() == 0 || tar == 0)
            return 0;
        
        vector<int> dp(tar + 1, 1e8);
        
        int ans = coinHeight(arr, tar, dp);
        
        return ans != 1e8 ? ans : -1;
    }
    
    int coinHeight(vector<int> &arr, int tar, vector<int> &dp)
    {
        dp[0] = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int t = 1; t <= tar; t++)
            {
                if (t - arr[i] >= 0)
                {
                    dp[t] = min(dp[t], dp[t - arr[i]] + 1);  
                }
            }
        }
        return dp[tar];
    }
};