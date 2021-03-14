class Solution {
    public boolean hasAllCodes(String s, int k) {
        Set<String> str = new HashSet<String>();
        for (int i = 0; i <= s.length() - k; i++) {
            str.add(s.substring(i, i + k));
        }
        return str.size() == Math.pow(2, k);
    }
}