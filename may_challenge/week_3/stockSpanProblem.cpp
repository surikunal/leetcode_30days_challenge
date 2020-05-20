#include <iostream>
#include <stack>
using namespace std;
auto SpeedUp = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();
class StockSpanner
{
public:
    stack<int> prices;
    stack<int> weight;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int w = 1;
        while (!prices.empty())
        {
            int curr = prices.top();
            if (curr <= price)
            {
                w += weight.top();
                prices.pop();
                weight.pop();
            }
            else
                break;
        }
        prices.push(price);
        weight.push(w);
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */