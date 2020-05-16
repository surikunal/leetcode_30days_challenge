class Solution {
    public int kadans(int i, int j, int[] arr, int sign) {
        int ans = Integer.MIN_VALUE;
        int curr = Integer.MIN_VALUE;
        for (int k = i; k <= j; k++) {
            curr = (sign * arr[k]) + Math.max(0, curr);
            ans = Math.max(curr, ans);
        }
        return ans;
    }

    public int maxSubarraySumCircular(int[] A) {
        if (A.length == 1)
            return A[0];
        int S = 0;
        for (int i : A)
            S += i;
        int ans1 = kadans(0, A.length - 1, A, 1);
        int ans2 = S + kadans(1, A.length - 1, A, -1);
        int ans3 = S + kadans(0, A.length - 2, A, -1);
        return Math.max(ans1, Math.max(ans2, ans3));
    }
}