#include <iostream>
#include <cmath>
using namespace std;
auto SpeedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        double i = sqrt(num);
        return (int)i == i;
    }
};