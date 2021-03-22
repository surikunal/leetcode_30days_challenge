class Solution {
    public boolean reorderedPowerOf2(int N) {
        int countArr[] = count(N);
        for (int i = 0; i < 31; i++) {
            if (Arrays.equals(countArr, count(1 << i)))
                return true;
        }
        return false;
    }
    
    public int[] count(int n) {
        int[] c = new int[10];
        while (n != 0) {
            c[n % 10]++;
            n /= 10;
        }
        return c;
    }
}