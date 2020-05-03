#include <unordered_set>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_set<char> map(J.begin(), J.end());
        for (char s: S) 
        {
            if (map.count(s))
                count++;
        }
        return count;
    }
};