/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    TreeNode bst(int[] arr, int idx, int size) {
        if (idx >= size)
            return null;

        int val = arr[idx];
        TreeNode root = new TreeNode(val);

        int i = idx + 1;
        while (i <= arr.length - 1 && arr[i] < val) {
            i++;
        }
        root.left = bst(arr, idx + 1, i);
        root.right = bst(arr, i, size);

        return root;
    }

    public TreeNode bstFromPreorder(int[] preorder) {
        return bst(preorder, 0, preorder.length);
    }
}