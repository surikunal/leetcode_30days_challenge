#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq;

    for (auto i : stones)
    {
        pq.push(i);
    }

    while (pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();

        int x = pq.top();
        pq.pop();

        if (y != x)
            pq.push(y - x);
    }
    pq.push(0);
    return pq.top();
}

int main(int args, char **argv)
{
    vector<int> arr = {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(arr) << endl;
    return 0;
}