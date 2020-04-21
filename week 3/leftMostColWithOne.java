/**
 * // This is the BinaryMatrix's API interface. // You should not implement it,
 * or speculate about its implementation interface BinaryMatrix { public int
 * get(int x, int y) {} public List<Integer> dimensions {} };
 */

class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        List<Integer> dim = binaryMatrix.dimensions();
        int rows = dim.get(0);
        int cols = dim.get(1);

        if (rows == 0 || cols == 0)
            return -1;

        int result = -1;
        int r = 0, c = cols - 1;
        while (r < rows && c >= 0) {
            if (binaryMatrix.get(r, c) == 1) {
                result = c;
                c--;
            } else {
                r++;
            }
        }
        return result;
    }
}