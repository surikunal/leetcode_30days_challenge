#include <iostream>
#include <unordered_map>
using namespace std;
class LRUCache
{
public:
    // class LRUCache
    // {
    int key;
    int val;
    LRUCache *prev;
    LRUCache *next;
    // };

    unordered_map<int, LRUCache *> map;
    int cache_capacity;
    LRUCache *head;
    LRUCache *tail;
    LRUCache(int capacity)
    {
        this->cache_capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        int result = -1;
        LRUCache *node = map[key];
        if (node != nullptr)
        {
            result = node->val;
            remove(node);
            add(node);
        }
        return result;
    }

    void put(int key, int value)
    {
        LRUCache *node = map[key];
        if (node != nullptr)
        {
            remove(node);
            node->val = value;
            add(node);
        }
        else
        {
            if (map.size() == cache_capacity)
            {
                map.erase(tail->prev->key);
                remove(tail->prev);
            }
            LRUCache *new_node;
            new_node->key = key;
            new_node->val = value;

            map[key] = new_node;
            add(new_node);
        }
    }

    void add(LRUCache *node)
    {
        LRUCache *head_next = head->next;
        head->next = node;
        node->prev = head;
        node->next = head_next;
        head_next->prev = node;
    }

    void remove(LRUCache *node)
    {
        LRUCache *node_prev = node->prev;
        LRUCache *node_next = node->next;

        node_prev->next = node_next;
        node_next->prev = node_prev;
    }
};