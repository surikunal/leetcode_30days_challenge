#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k1 = 0, k2 = nums.size() - 1;
        int i = 0;
        while(i != nums.size()) {
            if(i > k2)
                break;
            if(nums[i] == 0) {
                if(i == k1) {
                    i++;
                    k1++;
                }
                else {
                    swap(nums[k1++], nums[i]);
                }
            }
            else if(nums[i] == 2) {
                if(i == k2) {
                    i++;
                    k2--;
                }
                else
                    swap(nums[k2--], nums[i]);
            }
            else {
                i++;
            }
        }
    }
};