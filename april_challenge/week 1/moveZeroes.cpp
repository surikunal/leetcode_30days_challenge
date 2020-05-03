#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int itr = 0, ptr = 0;
        for (int i = 0; i < arr.size(); i++){
            if (arr[itr] != 0) {
                swap(arr[itr], arr[ptr]);
                ptr++;
            }
            itr++;
        }
    }
};