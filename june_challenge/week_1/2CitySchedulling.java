// using sorting
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int n = costs.length;
        Arrays.sort(costs, (a, b) -> (a[0] - a[1]) - (b[0] - b[1]));
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += i >= n / 2 ? costs[i][1] : costs[i][0];
        return ans;
    }
}