#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)      // O(N + klog(k))
{
    unordered_map<string, vector<string>> map;
    string temp;
    for (int i = 0; i < strs.size(); i++)
    {
        temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        map[strs[i]].push_back(temp);
    }

    vector<vector<string>> ans;
    for (auto idx = map.begin(); idx != map.end(); idx++)
    {
        ans.push_back(idx->second);
    }
    return ans;
}

int main(int args, char **argv)
{
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(str);
    return 0;
}