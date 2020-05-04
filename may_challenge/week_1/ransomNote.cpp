#include <iostream>
#include <vector>
using namespace std;
static vector<int> nums = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> freq(26, 0);
        for (char c : magazine)
            freq[c - 'a']++;
        for (char c : ransomNote)
            if (--freq[c - 'a'] < 0)
                return false;
        return true;
    }
};