class Solution
{
public:
    int firstUniqChar(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int arr[26] = {0};
        for (char i : s)
            arr[i - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (arr[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};