#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void swap(vector<char> &arr, int si, int ei)
    {
        int temp = arr[si];
        arr[si] = arr[ei];
        arr[ei] = temp;
    }
    void reverseString(vector<char> &s)
    {
        int si = 0, ei = s.size() - 1;
        while (si <= ei)
        {
            swap(s, si, ei);
            si++;
            ei--;
        }
    }
};