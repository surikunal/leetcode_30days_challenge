public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public ArrayList<Integer> inorder(TreeNode node, ArrayList<Integer> arr) {
        if (node == null)
            return arr;
        inorder(node.left, arr);
        arr.add(node.val);
        inorder(node.right, arr);
        return arr;
    }

    public int kthSmallest(TreeNode root, int k) {
        ArrayList<Integer> ans = inorder(root, new ArrayList<Integer>());
        return ans.get(k - 1);
    }
}