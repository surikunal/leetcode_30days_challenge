class Solution {
    public int majorityElement(int[] arr) {
        int freq = 1, suspect = arr[0];
        for (int i = 1; i < arr.length; i++)
        {
            if (suspect == arr[i])
            {
                freq++;
            }
            
            else
            {
                freq--;
            }
            
            if (freq == 0)
            {
                suspect = arr[i];
                freq = 1;
            }
        }
        return suspect;
    }
}