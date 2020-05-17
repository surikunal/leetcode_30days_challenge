#include <iostream>
#include <vector>
using namespace std;
auto SpeedUp = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        vector<int> ans;
        int window = p.size();
        int len = s.size();
        if (window == 0 || len == 0 || window > len)
            return ans;
        int st = 0, end = 0;
        // for first iteration only
        while (end < window)
        {
            phash[p[end] - 'a']++;
            hash[s[end] - 'a']++;
            end++;
        }
        end--;
        // for rest of iterations
        while (end < len)
        {
            if (phash == hash)
                ans.push_back(st);
            end++;
            hash[s[st] - 'a']--;
            if (end != len)
                hash[s[end] - 'a']++;
            st++;
        }
        return ans;
    }
};