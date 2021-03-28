class Solution {
    public:
        int countSubstrings(string s) {
            vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
            int count = 0;
            for (int gap = 0; gap < s.size(); gap++) {
                for (int i = 0, j = gap; j < s.size(); i++, j++) {
                    if ((gap == 0) or (gap == 1 and s[i] == s[j]) or (s[i] == s[j] and dp[i + 1][j - 1] != 0))
                        dp[i][j] = gap + 1;
                    count += dp[i][j] != 0 ? 1 : 0;
                }
            }
            return count;
        }
    };