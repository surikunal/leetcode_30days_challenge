#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// using sorting
class Solution
{
public:
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[1] - a[0] > b[1] - b[0];
    }
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        sort(costs.begin(), costs.end(), comparator);
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += i >= n / 2 ? costs[i][1] : costs[i][0];
        return ans;
    }
};

// using heap
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < costs.size(); i++)
            pq.push(make_pair(costs[i][0] - costs[i][1], i));

        int ans = 0;
        for (int i = 0; i < pq.size() / 2; i++)
        {
            ans += costs[pq.top().second][1];
            pq.pop();
        }

        for (int i = 0; i < pq.size() / 2; i++)
        {
            ans += costs[pq.top().second][0];
            pq.pop();
        }
        return ans;
    }
};
