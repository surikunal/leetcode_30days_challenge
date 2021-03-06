class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> ans = new ArrayList<>();
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);
        while (!que.isEmpty()) {
            long sum = 0;
            long count = 0;
            Queue<TreeNode> temp = new LinkedList<>();
            while (!que.isEmpty()) {
                TreeNode n = que.remove();
                sum += n.val;
                count++;
                if (n.left != null) {
                    temp.add(n.left);
                }
                if (n.right != null) {
                    temp.add(n.right);
                }
            }
            que = temp;
            ans.add(sum * 1.0 / count);
        }
        return ans;
    }
}