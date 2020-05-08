struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rootHeight(TreeNode *node, int data, int height, int &parent)
    {
        if (!node)
            return 0;
        if (node->val == data)
            return height;
        parent = node->val;
        int left = rootHeight(node->left, data, height + 1, parent);
        if (left)
            return left;
        parent = node->val;
        int right = rootHeight(node->right, data, height + 1, parent);
        return right;
        }
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y)
            return false;
        int xparent = -1;
        int xHeight = rootHeight(root, x, 0, xparent);
        
        int yparent = -1;
        int yHeight = rootHeight(root, y, 0, yparent);
        
        if (xHeight == yHeight && xparent != yparent)
            return true;
        return false;
    }
};