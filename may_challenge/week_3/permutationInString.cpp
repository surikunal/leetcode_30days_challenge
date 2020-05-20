#include <iostream>
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
    bool check(int a[26], int b[26])
    {
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;
        int a[26] = {0}, b[26] = {0};
        for (char c : s1)
            a[c - 'a']++;
        int k = 0;
        for (int i = 0; i <= s2.length(); i++)
        {
            if (i >= s1.length())
            {
                if (check(a, b))
                {
                    k = 1;
                    break;
                }
                if (i >= s2.length())
                    break;
                b[s2[i] - 'a']++;
                b[s2[i - s1.length()] - 'a']--;
            }
            else
            {
                b[s2[i] - 'a']++;
            }
        }
        if (k == 1)
            return true;
        return false;
    }
};