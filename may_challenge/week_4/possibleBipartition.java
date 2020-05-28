class Solution {
    public boolean possibleBipartition(int N, int[][] dislikes) {
        int[] vis = new int[N];
        Arrays.fill(vis, -1);

        ArrayList<Integer>[] graphs = new ArrayList[N];
        for (int i = 0; i < N; i++)
            graphs[i] = new ArrayList();
        // making a graph
        for (int[] p : dislikes) {
            graphs[p[0] - 1].add(p[1] - 1);
            graphs[p[1] - 1].add(p[0] - 1);
        }
        for (int i = 0; i < N; i++) {
            if (vis[i] == -1 && !dfs(graphs, vis, i, 0)) {
                return false;
            }
        }
        return true;
    }

    public boolean dfs(ArrayList<Integer>[] graph, int[] vis, int i, int grp) {
        if (vis[i] == -1)
            vis[i] = grp;
        else
            return vis[i] == grp;

        for (int n : graph[i]) {
            if (!dfs(graph, vis, n, 1 - grp)) {
                return false;
            }
        }
        return true;
    }
}