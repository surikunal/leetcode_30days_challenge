#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isHappy(int n)
{
    set<int> mySet;
    int val;
    int idx;

    while (1)
    {
        val = 0;
        while (n)
        {
            idx = n % 10;
            val += idx * idx;
            n /= 10;
        }

        if (val == 1)
            return true;
        else if (mySet.find(val) != mySet.end())
            return false;

        mySet.insert(val);
        n = val;
    }
    return false;
}

int main(int args, char **argv)
{
    cout << (boolalpha) << isHappy(19) << endl;
    return 0;
}