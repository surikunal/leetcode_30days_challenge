auto SpeedUp = [](){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> graph(n + 1); // ArrayList<int[]>[] graph = new ArrayList[N];
        for (vector<int> &ar: flights)
            graph[ar[0]].push_back({ar[1],ar[2]});
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, K + 1});
        
        while (pq.size() != 0)
        {
            vector<int> rvtx = pq.top();
            pq.pop();
            
            if (rvtx[1] == dst)
                return rvtx[0];
            
            if (rvtx[2] == 0)
                continue;
            
            for (pair<int, int> &e: graph[rvtx[1]])
            {
                pq.push({rvtx[0] + e.second, e.first, rvtx[2] - 1});
            }
        }
        return -1;
    }
};