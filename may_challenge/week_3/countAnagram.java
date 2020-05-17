class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int[] map = new int[26];
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < p.length(); i++) {
            map[p.charAt(i) - 'a']++;
        }

        int windowStart = 0;
        int windowEnd = 0;
        while (windowEnd < s.length()) {
            if (map[s.charAt(windowEnd) - 'a'] > 0) {
                map[s.charAt(windowEnd) - 'a']--;
                windowEnd++;
                if (windowEnd - windowStart == p.length()) {
                    result.add(windowStart);
                }
            } else if (windowStart == windowEnd) {
                windowStart++;
                windowEnd++;
            } else {
                map[s.charAt(windowStart) - 'a']++;
                windowStart++;
            }
        }
        return result;
    }
}
