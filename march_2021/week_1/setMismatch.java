class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] freq = new int[nums.length + 1];
        int dup = -1, miss = -1;
        for (int i = 0; i < nums.length; i++) {
            freq[nums[i]] += 1;
        }
        for (int i = 1; i <= nums.length; ++i) {
            if (freq[i] == 2) {
                dup = i;
            } else if (freq[i] == 0) {
                miss = i;
            }
        }
        return new int[] { dup, miss };
    }
}

// ===================================================

class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] freq = new int[nums.length + 1];
        int dup = -1, miss = -1;
        for (int i = 0; i < nums.length; i++) {
            freq[nums[i]] += 1;
        }
        for (int i = 1; i <= nums.length; ++i) {
            if (freq[i] == 2) {
                dup = i;
            } else if (freq[i] == 0) {
                miss = i;
            }
        }
        return new int[] { dup, miss };
    }
}