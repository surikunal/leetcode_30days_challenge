class Solution {
    Set<String> perfect_word;
    Map<String, String> word_caseSensitive;
    Map<String, String> word_vowel;
    public String[] spellchecker(String[] wordlist, String[] queries) {
        perfect_word = new HashSet<String>();
        word_caseSensitive = new HashMap<String, String>();
        word_vowel = new HashMap<String, String>();
        
        for (String word: wordlist) {
            perfect_word.add(word);
            
            String wordLow = word.toLowerCase();
            word_caseSensitive.putIfAbsent(wordLow, word);
            
            String wordLowVowel = devowel(wordLow);
            word_vowel.putIfAbsent(wordLowVowel, word);
        }
        
        String[] ans = new String[queries.length];
        int t = 0;
        for (String s: queries)
            ans[t++] = solve(s);
        return ans;
    }
    
    public String solve(String query) {
        if (perfect_word.contains(query))
            return query;
        
        String queryLower = query.toLowerCase();
        if (word_caseSensitive.containsKey(queryLower))
            return word_caseSensitive.get(queryLower);
        
        String queryLowerVowel = devowel(queryLower);
        if (word_vowel.containsKey(queryLowerVowel))
            return word_vowel.get(queryLowerVowel);
        
        return "";
    }
    
    public String devowel(String vowel) {
        StringBuilder sb = new StringBuilder();
        for (char c: vowel.toCharArray())
            sb.append(isVowel(c) ? '*' : c);
        return sb.toString();
    }
    
    public boolean isVowel(char c) {
        return (c == 'a' || c == 'u' || c == 'o' || c == 'i' || c == 'e');
    }
}