#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    Node *next, *previous;
    int key, value;

    Node()
    {
        next = previous = nullptr;
        key = value = -1;
    }

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        next = previous = nullptr;
    }
};

class LRUCache
{
private:
    Node *head, *tail;
    int maxCapacity, currentCapacity;
    unordered_map<int, Node *> uMap;

public:
    LRUCache(int capacity)
    {
        maxCapacity = capacity;
        currentCapacity = 0;
        head = new Node();
        tail = new Node();

        head->previous = tail;
        tail->next = head;
    }

    int get(int key)
    {
        if (uMap.find(key) == uMap.end())
            return -1;
        Node *node = uMap[key];
        int value = node->value;

        uMap.erase(key);
        eraseNode(node);
        addNode(key, value);

        return value;
    }

    void put(int key, int value)
    {
        if (uMap.find(key) != uMap.end())
        {
            currentCapacity--;
            Node *currentNode = uMap[key];
            uMap.erase(key);
            eraseNode(currentNode);
        }
        if (currentCapacity == maxCapacity)
        {
            uMap.erase(tail->next->key);
            eraseNode(tail->next);
            currentCapacity--;
        }
        addNode(key, value);
        currentCapacity++;
    }

    void eraseNode(Node *node)
    {
        node->previous->next = node->next;
        node->next->previous = node->previous;
        delete node;
    }

    void addNode(int key, int value)
    {
        Node *node = new Node(key, value);
        node->next = head;
        node->previous = head->previous;
        head->previous->next = node;
        head->previous = node;
        uMap[key] = node;
    }
};