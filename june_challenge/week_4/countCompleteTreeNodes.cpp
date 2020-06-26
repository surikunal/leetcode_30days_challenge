#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// O(N) approch
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        if (!root)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// O(logN * logN) approch
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        if (!root)
            return 0;
        TreeNode *l = root->left;
        int left_level = 1;
        while (l)
        {
            l = l->left;
            left_level++;
        }
        TreeNode *r = root->right;
        int right_level = 1;
        while (r)
        {
            r = r->right;
            right_level++;
        }
        if (left_level == right_level)
            return pow(2, left_level) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
