#include <iostream>
#include <vector>
using namespace std;
auto SpeedUp = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int src)
    {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
            return;
        if (image[sr][sc] != src)
            return;

        image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, newColor, src);
        dfs(image, sr, sc - 1, newColor, src);
        dfs(image, sr + 1, sc, newColor, src);
        dfs(image, sr, sc + 1, newColor, src);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (newColor == image[sr][sc])
            return image;
        int sourse = image[sr][sc];
        dfs(image, sr, sc, newColor, sourse);
        return image;
    }
};