class MyHashMap {
    int[] map;

    /** Initialize your data structure here. */
    public MyHashMap() {
        map = new int[1000000];
        Arrays.fill(map, -1);
    }

    /** value will always be non-negative. */
    public void put(int key, int value) {
        map[key] = value;
    }

    /**
     * Returns the value to which the specified key is mapped, or -1 if this map
     * contains no mapping for the key
     */
    public int get(int key) {
        if (key < 0 || key > 1000000 || map[key] == -1) {
            return -1;
        } else {
            return map[key];
        }
    }

    /**
     * Removes the mapping of the specified value key if this map contains a mapping
     * for the key
     */
    public void remove(int key) {
        map[key] = -1;
    }
}