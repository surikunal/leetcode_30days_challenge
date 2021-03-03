class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        boolean[] check = new boolean[n + 1];
        for (int i : nums) {
            check[i] = true;
        }
        for (int i = 0; i <= n; i++) {
            if (check[i] == false) {
                return i;
            }
        }
        return -1;
    }
}