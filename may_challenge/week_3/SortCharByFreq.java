class Solution {
    // steps:
    // first we will make a HashMap for charater vs Frequency
    // then we will make a List in which each character is placed at its freq
    // position
    // finally we will print each character its idx times (move from last)
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        // making a map of char vs freq
        for (char c : s.toCharArray())
            map.put(c, map.getOrDefault(c, 0) + 1);

        // making a List of arrays for saving characters at its idx position
        List<Character>[] bucket = new List[s.length() + 1]; // size = length+1 bcz when all characters are same then
                                                             // the freq is length+1
        for (char keys : map.keySet()) {
            int freq = map.get(keys);
            if (bucket[freq] == null)
                bucket[freq] = new ArrayList<>();
            bucket[freq].add(keys);
        }

        // traversing in list to print all characters , their freq num of times
        // NOTE: this is not O(N^3), This is O(N)
        StringBuilder sb = new StringBuilder();
        for (int i = bucket.length - 1; i >= 0; i--) {
            if (bucket[i] != null) {
                for (char c : bucket[i]) {
                    for (int j = 0; j < i; j++) {
                        sb.append(c);
                    }
                }
            }
        }
        return sb.toString();
    }
}