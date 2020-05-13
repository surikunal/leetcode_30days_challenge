class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (newColor == image[sr][sc])
            return image;
        int src = image[sr][sc];
        dfs(image, sr, sc, newColor, src);
        return image;
    }

    public void dfs(int[][] image, int sr, int sc, int newColor, int src) {
        if (sr < 0 || sc < 0 || sr >= image.length || sc >= image[0].length)
            return;
        if (image[sr][sc] != src)
            return;

        image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, newColor, src);
        dfs(image, sr, sc - 1, newColor, src);
        dfs(image, sr + 1, sc, newColor, src);
        dfs(image, sr, sc + 1, newColor, src);
    }
}