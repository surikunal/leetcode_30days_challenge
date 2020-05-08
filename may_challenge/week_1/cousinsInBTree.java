class Solution {
    public ArrayList<TreeNode> rootToNode(TreeNode node, int data)
    {
        if (node == null)
            return null;
        if (node.val == data)
        {
            ArrayList<TreeNode> base = new ArrayList<>();
            base.add(node);
            return base;
        }
        ArrayList<TreeNode> leftAns = rootToNode(node.left, data);
        if (leftAns != null)
        {
            leftAns.add(node);
            return leftAns;
        }
        ArrayList<TreeNode> rightAns = rootToNode(node.right, data);
        if (rightAns != null)
        {
            rightAns.add(node);
            return rightAns;
        }
        return null;
    }
    public boolean isCousins(TreeNode root, int x, int y) {
        ArrayList<TreeNode> ans1 = rootToNode(root, x);
        ArrayList<TreeNode> ans2 = rootToNode(root, y);
        if (ans1.size() != ans2.size() || ans1.get(1) == ans2.get(1))
            return false;
        return true;
    }
}