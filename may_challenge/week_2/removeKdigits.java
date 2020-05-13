class Solution {
    public String removeKdigits(String num, int k) {
        char[] arr = num.toCharArray();
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            while (st.size() != 0 && st.peek() > arr[i] && k != 0) {
                st.pop();
                k--;
            }
            st.push(arr[i]);
        }

        while (k-- > 0) {
            st.pop();
        }

        StringBuilder sb = new StringBuilder();
        while (st.size() != 0) {
            sb.append(st.pop());
        }

        if (sb.length() != 0 && sb.charAt(sb.length() - 1) == '0') {
            int i = sb.length() - 2;
            for (; i >= 0; i--) {
                if (sb.charAt(i) != '0') {
                    break;
                }
            }
            sb = new StringBuilder(sb.substring(0, i + 1));
        }
        sb.reverse();
        String ans = sb.toString();
        return ans.length() != 0 ? ans : "0";
    }
}