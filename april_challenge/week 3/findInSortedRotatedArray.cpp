#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> &arr, int target)
{
    int si = 0;
    int ei = arr.size() - 1;

    while (si <= ei)
    {
        int mid = (si + ei) >> 1;
        if (arr[mid] == target)
            return mid;

        if (arr[mid] <= arr[ei])
        {
            if ((target > arr[mid]) && (target <= arr[ei]))
                si = mid + 1;
            else
                ei = mid - 1;
        }

        if (arr[mid] >= arr[si])
        {
            if ((target < arr[mid]) && (target >= arr[si]))
                ei = mid - 1;
            else
                si = mid + 1;
        }
    }
    return -1;
}

int main(int args, char **argv)
{
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search(arr, target) << endl;
    return 0;
}