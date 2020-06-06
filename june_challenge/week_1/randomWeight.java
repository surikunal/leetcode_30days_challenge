class Solution {
    private int[] w_sum;
    private int sum;

    public Solution(int[] w) {
        sum = 0;
        w_sum = new int[w.length];
        for (int i = 0; i < w.length; i++) {
            sum += w[i];
            w_sum[i] = sum;
        }
    }

    public int pickIndex() {
        int idx = (int) (Math.random() * sum);
        return bs(idx + 1);
    }

    public int bs(int val) {
        int l = 0;
        int r = w_sum.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (w_sum[mid] < val)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
}