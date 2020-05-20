class Solution {
    public boolean check(int[] a, int[] b) {
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i])
                return false;
        return true;
    }

    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        int[] a = new int[26];
        int[] b = new int[26];
        for (int c = 0; c < s1.length(); c++)
            a[s1.charAt(c) - 'a']++;
        int k = 0;
        for (int i = 0; i <= s2.length(); i++) {
            if (i >= s1.length()) {
                if (check(a, b)) {
                    k = 1;
                    break;
                }
                if (i >= s2.length())
                    break;
                b[s2.charAt(i) - 'a']++;
                b[s2.charAt(i - s1.length()) - 'a']--;
            } else {
                b[s2.charAt(i) - 'a']++;
            }
        }
        if (k == 1)
            return true;
        return false;
    }
}