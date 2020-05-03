#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxprofit = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        if (prices[i] < prices[i + 1])
        {
            maxprofit += prices[i + 1] - prices[i];
        }
    }
    return maxprofit;
}

int main(int args, char **argv)
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr) << endl;
    return 0;
}