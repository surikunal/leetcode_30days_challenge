class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] check = new boolean[rooms.size()];
        check[0] = true;
        Stack<Integer> st = new Stack<>();
        st.push(0);
        while (!st.isEmpty()) {
            int node = st.pop();
            for (int i: rooms.get(node)) {
                if (!check[i]) {
                    check[i] = true;
                    st.push(i);
                }
            }
        }
        for (boolean i: check) {
            if (!i) {
                return false;
            }
        }
        return true;
    }
}