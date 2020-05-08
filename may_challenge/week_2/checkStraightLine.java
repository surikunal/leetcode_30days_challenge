class Solution {
    public boolean checkStraightLine(int[][] arr) {
        if (arr.length <= 1)
            return true;
        double num = (double)(arr[1][1]-arr[0][1]);
        double denum = (double)(arr[1][0]-arr[0][0]);
        double m = (num/denum);
        for (int i = 2; i < arr.length; i++)
        {
            double slope = ((double)(arr[i][1]-arr[i-1][1])/(double)(arr[i][0]-arr[i-1][0]));
            if (slope != m)
                return false;
        }
        return true;
    }
}