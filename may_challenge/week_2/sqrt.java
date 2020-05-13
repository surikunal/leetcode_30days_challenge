class Solution {
    public boolean isPerfectSquare(int num) {
        double i = Math.sqrt(num);
        return (int) i == i;
    }
}