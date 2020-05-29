#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> kahnsAlgo(int n, vector<vector<int>> &graph, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(n, 0);
        // this is bcz
        // ar[1] is reqd to do ar[0]
        for (vector<int> ar : prerequisites)
        {
            indegree[ar[1]]++;
        }

        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }

        vector<int> ans;
        while (que.size() != 0)
        {
            int size = que.size();
            while (size-- > 0)
            {
                int rvtx = que.front();
                que.pop();

                // === line is written after full code ====
                ans.push_back(rvtx);
                // ========================================

                for (int ele : graph[rvtx])
                {
                    if (--indegree[ele] == 0)
                    {
                        que.push(ele);
                    }
                }
            }
        }
        return ans;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        // that is how we make graph

        vector<vector<int>> graph(numCourses, vector<int>());
        for (vector<int> ar : prerequisites)
        {
            graph[ar[0]].push_back(ar[1]);
        }

        // now call kahns algo
        vector<int> ans = kahnsAlgo(numCourses, graph, prerequisites);

        return ans.size() == numCourses;
    }
};
auto SpeedUp = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();