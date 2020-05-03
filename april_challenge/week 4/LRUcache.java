class LRUCache {
    class Node {
        Node prev;
        Node next;
        int key;
        int val;
    }
    // we are using hashmap for fast acess and doubly linked list for fast removal of node
    final Node head = new Node();   // final is bcz we are never going to change it
    final Node tail = new Node();
    Map<Integer, Node> map;
    int cache_capacity;
    
    public LRUCache(int capacity) {
        map = new HashMap(capacity);
        this.cache_capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        int result = -1;
        Node node = map.get(key);
        if (node != null) {
            result = node.val;
            remove(node);
            add(node);
        }
        return result;
    }
    
    public void put(int key, int value) {
        Node node = map.get(key);
        if(node != null) {
            remove(node);
            node.val = value;
            add(node);
        } else {
            if (map.size() == cache_capacity) {
                map.remove(tail.prev.key);// remove from hashmap
                remove(tail.prev);// remove from doubly linked list
            }
            Node new_node = new Node();
            new_node.key = key;
            new_node.val = value;
            
            map.put(key, new_node);
            add(new_node);
        }
    }
    
    public void add(Node node) {
        Node head_next = head.next;
        head.next = node;
        node.prev = head;
        node.next = head_next;
        head_next.prev = node;
    }
    
    public void remove(Node node) {
        Node next_node = node.next;
        Node prev_node = node.prev;
        
        next_node.prev = prev_node;
        prev_node.next = next_node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */