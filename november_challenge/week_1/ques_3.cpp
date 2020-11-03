auto SpeedUp = [](){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();
class Solution {
public:
    int maxPower(string s) {
        int ans = 1, count = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                count++;
            else
                count = 1;
            
            ans = max(ans, count);
        }
        return ans;
    }
};