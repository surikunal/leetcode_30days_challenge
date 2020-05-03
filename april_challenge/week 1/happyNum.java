import java.util.HashSet;

class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> mySet = new HashSet();
        int val = 0, idx = 0;
        while (1 != 0)
        {
            val = 0;
            while (n != 0)
            {
                idx = n % 10;
                val += idx * idx;
                n /= 10;   
            }
            
            if (val == 1)
                return true;
            else if (mySet.contains(val))
                return false;
            
            mySet.add(val);
            n = val;
        }
        // return false;
    }
}