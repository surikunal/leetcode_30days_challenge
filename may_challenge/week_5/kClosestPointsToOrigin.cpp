#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//* O(NlogN)
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = points.size();
        // multimap is sorted in ascending order according to key
        multimap<int, int> map; // distance vs index
        for (int i = 0; i < n; i++)
            map.insert({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});

        vector<vector<int>> ans;
        // store first K points from multimap
        int count = 0;
        for (auto it = map.begin(); count < K; it++, count++)
            ans.push_back(points[it->second]);
        return ans;
    }
};
//===========================================================
//* O(N + Nlog(N))
auto SpeedUp = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        int dist;
        vector<pair<int, pair<int, int>>> v;
        for (vector<int> ar : points)
        {
            dist = ar[0] * ar[0] + ar[1] * ar[1];
            v.push_back({dist, {ar[0], ar[1]}});
        }
        sort(v.begin(), v.end());
        vector<vector<int>> ans(K);
        for (int i = 0; i < K; i++)
        {
            ans[i].push_back(v[i].second.first);
            ans[i].push_back(v[i].second.second);
        }
        return ans;
    }
};