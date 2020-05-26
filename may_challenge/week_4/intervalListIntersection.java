class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        int Asize = A.length;
        int Bsize = B.length;
        int Aptr = 0;
        int Bptr = 0;
        List<int[]> ans = new ArrayList<>();
        while (Aptr < Asize && Bptr < Bsize) {
            int lo = Math.max(A[Aptr][0], B[Bptr][0]);
            int hi = Math.min(A[Aptr][1], B[Bptr][1]);
            if (lo <= hi)
                ans.add(new int[] { lo, hi });

            if (A[Aptr][1] > B[Bptr][1])
                Bptr++;
            else
                Aptr++;
        }
        return ans.toArray(new int[ans.size()][]);
    }
}