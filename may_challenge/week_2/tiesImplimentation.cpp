#include <iostream>
#include <vector>
using namespace std;
class Trie
{
public:
    class Node
    {
    public:
        int wordEnd = 0;
        vector<Node *> childs;

        Node()
        {
            this->childs.assign(26, nullptr);
            this->wordEnd = 0;
        }
    };
    /** Initialize your data structure here. */
    Trie()
    {
    }
    Node *root = new Node();

    void insert(string word)
    {
        Node *curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';
            if (curr->childs[idx] == nullptr)
            {
                curr->childs[idx] = new Node();
            }
            curr = curr->childs[idx];
        }
        curr->wordEnd++;
    }

    bool search(string word)
    {
        Node *curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';
            curr = curr->childs[idx];

            if (curr == nullptr)
                return false;
        }
        return curr->wordEnd > 0;
    }

    bool startsWith(string prefix)
    {
        Node *curr = root;
        int n = prefix.length();
        for (int i = 0; i < n; i++)
        {
            int idx = prefix[i] - 'a';
            curr = curr->childs[idx];

            if (curr == nullptr)
                return false;
        }
        return true;
    }
};