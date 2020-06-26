class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            // Find sum of set bits at ith position in all
            // array elements
            for (int j = 0; j < nums.length; j++) {
                if ((nums[j] & (1 << i)) != 0) {
                    count++; // counting num of bits...so it should be multiple of 3 for all numbers which
                             // are repeating thrice
                }
            }
            result = result | ((count % 3) << i);// only true for sum = 1 and 2 (and sum will never be 2)
            // when sum is not multiple of 3 then it means the num is appearing only once so
            // we ON all its bits which make it that num
        }
        return result;
    }
}