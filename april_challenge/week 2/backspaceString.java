class Solution {
    public boolean backspaceCompare(String S, String T) {
        return StringCompare(S).equals(StringCompare(T));
    }
    public String StringCompare(String str) {
        StringBuilder sb = new StringBuilder();
        for (char c: str.toCharArray())
        {
            if (c != '#')
                sb.append(c);
            else if (sb.length() > 0)
                sb.deleteCharAt(sb.length() - 1);
        }
        return sb.toString();
    }
}