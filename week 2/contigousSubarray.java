import java.util.HashMap;
class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();    // sum vs index
        
        int sum = 0;
        int logestSubArray = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1)
                sum += 1;
            else
                sum += -1;
            
            if (sum == 0)
            {
                if (logestSubArray < i + 1)
                {
                    logestSubArray = i + 1;
                }
            }
            else if (map.containsKey(sum))
            {
                if (logestSubArray < i - map.get(sum))
                {
                    logestSubArray = i - map.get(sum);
                }
            }
            else 
            {
                map.put(sum, i);
            }
        }
        return logestSubArray;
    }
}