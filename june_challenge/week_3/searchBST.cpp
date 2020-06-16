#include <iostream>
#include <vector>
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
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        TreeNode *curr = root;
        while (curr)
        {
            if (curr->val == val)
                return curr;
            else if (curr->val > val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return nullptr;
    }
};