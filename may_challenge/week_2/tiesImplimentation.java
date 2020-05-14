class Trie {
    class Node {
        int wordEnd = 0;
        Node[] childs;

        Node() {
            this.childs = new Node[26];
            this.wordEnd = 0;
        }
    }

    /** Initialize your data structure here. */
    public Trie() {

    }

    Node root = new Node();

    /** Inserts a word into the trie. */
    public void insert(String word) {
        Node curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int idx = word.charAt(i) - 'a';
            if (curr.childs[idx] == null)
                curr.childs[idx] = new Node();

            curr = curr.childs[idx];
        }
        curr.wordEnd++;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Node curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int idx = word.charAt(i) - 'a';
            curr = curr.childs[idx];

            if (curr == null)
                return false;
        }
        return curr.wordEnd > 0;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String word) {
        Node curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int idx = word.charAt(i) - 'a';
            curr = curr.childs[idx];

            if (curr == null)
                return false;
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such: Trie obj = new
 * Trie(); obj.insert(word); boolean param_2 = obj.search(word); boolean param_3
 * = obj.startsWith(prefix);
 */