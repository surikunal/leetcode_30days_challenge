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

class Solution {
    public int missingNumber(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            ans ^= nums[i];
            ans ^= i;
        }
        ans ^= nums.length;
        return ans;
    }
}

class Solution {
    public int missingNumber(int[] nums) {
        int expectedSum = nums.length * (nums.length + 1) / 2;
        int actualSum = 0;
        for (int i: nums) {
            actualSum += i;
        }
        return expectedSum - actualSum;
    }
}