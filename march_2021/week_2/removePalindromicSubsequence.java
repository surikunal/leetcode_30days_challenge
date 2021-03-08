class Solution {
    public boolean pali(String s) {
        int si = 0, ei = s.length() - 1;
        while (si < ei) {
            if (s.charAt(si) != s.charAt(ei))
                return false;
            si++;
            ei--;
        }
        return true;
    }
    public int removePalindromeSub(String s) {
        if (s.length() == 0) {
            return 0;
        }
        if (pali(s) == true) {
            return 1;
        } else {
            return 2;
        }
    }
}