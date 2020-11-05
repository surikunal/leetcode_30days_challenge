class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
            
            vector<int> leaves;
            
            vector<int> degree(n, 0);
            //degree[i] = 1 -> leaf node
            
            unordered_map<int, unordered_set<int>> adj;
            
            
            //create the adjacency map
            
            for(int i=0;i<edges.size();i++){
                adj[edges[i][0]].insert(edges[i][1]);
                adj[edges[i][1]].insert(edges[i][0]);
                
                degree[edges[i][0]]++;
                degree[edges[i][1]]++;
            }
            
            
            for(int i=0;i<n;i++){
                if(degree[i]==1){
                    leaves.push_back(i);
                }
            }
            
            
            
            if(n==1){
                return {0};
            }
            
            vector<int> newLeaves;
            
            while(n>2){
                
                n = n - leaves.size();
                int size = leaves.size();
                
                for(int i=0;i<size;i++){
                    int cur = leaves[i];
                    for(int nei : adj[cur]){
                        adj[nei].erase(cur);
                        degree[nei]--;
                        
                        if(degree[nei] == 1){
                            newLeaves.push_back(nei);
                        }
                    }
                }
                
                
                //newLeaves now contain the leaves of my new graph
                
                leaves = newLeaves;
                newLeaves = vector<int> ();
            }
            
            
            return leaves;
            
        }
    };