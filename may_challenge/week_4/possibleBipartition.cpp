#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        vector<int> vis(N, -1);
        vector<vector<int>> graphs(N, vector<int>());
        // making a graph
        for (vector<int> &p : dislikes)
        {
            graphs[p[0] - 1].push_back(p[1] - 1);
            graphs[p[1] - 1].push_back(p[0] - 1);
        }
        for (int i = 0; i < N; i++)
        {
            if (vis[i] == -1 && !dfs(graphs, vis, i, 0))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &vis, int i, int grp)
    {
        if (vis[i] == -1)
            vis[i] = grp;
        else
            return vis[i] == grp;

        for (int n : graph[i])
        {
            if (!dfs(graph, vis, n, 1 - grp))
            {
                return false;
            }
        }
        return true;
    }
};
auto SpeedUp = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();