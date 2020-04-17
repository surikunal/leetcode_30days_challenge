#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &arr)
{
    int n = arr.size();
    vector<int> left(arr.size());
    left[0] = arr[0];
    vector<int> right(arr.size());
    right[n - 1] = arr[n - 1];
    for (int i = 1; i < arr.size() - 1; i++)
    {
        left[i] = arr[i] * left[i - 1];
        right[n - i - 1] = arr[n - i - 1] * right[n - i];
    }
    arr[0] = right[1];
    arr[n - 1] = left[n - 2];
    for (int i = 1; i < arr.size() - 1; i++)
    {
        arr[i] = left[i - 1] * right[i + 1];
    }
    return arr;
}

int main(int args, char **argv)
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(arr);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}