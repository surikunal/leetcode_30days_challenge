#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *bst(vector<int> &arr, int idx, int size)
    {
        if (idx >= size)
            return nullptr;

        int val = arr[idx];
        TreeNode *root = new TreeNode(val);

        int i = idx + 1;
        while (i <= arr.size() - 1 && arr[i] < val)
        {
            i++;
        }
        root->left = bst(arr, idx + 1, i);
        root->right = bst(arr, i, size);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return bst(preorder, 0, preorder.size());
    }
};