
#include <iostream>
using namespace std;
class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = heightT(root->left);
    int rh = heightT(root->right);

    int dia = lh + rh + 2;

    return max(dia, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}

int heightT(TreeNode *node)
{
    if (node == NULL)
        return -1;

    return max(heightT(node->left), heightT(node->right)) + 1;
}

int main(int args, char ** argv) {
    //just make a tree here with name root and pass it in the function
    cout << diameterOfBinaryTree(root) << endl;
}