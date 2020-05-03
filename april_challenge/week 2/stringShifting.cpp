#include <iostream>
#include <vector>
using namespace std;

string stringShift(string s, vector<vector<int>> &shift)
{
    int val = 0;
    for (int i = 0; i < shift.size(); ++i)
    {
        if (shift[i][0] == 0)
        {
            val -= shift[i][1];
        }
        else
        {
            val += shift[i][1];
        }
    }

    int len = s.length();
    val %= len;
    string ans = "";
    if (val > 0)
        ans = s.substr(len - val, val) + s.substr(0, len - val);
    else if (val < 0)
        ans = s.substr(-val, len + val) + s.substr(0, -val); // negetive sign is to convert negetive value to positive value
    else
        ans = s;

    return ans;
}

int main(int args, char **argv)
{
    string str = "abc";
    vector<vector<int>> shift = {{0, 1}, {1, 2}};
    cout << stringShift(str, shift) << endl;
    return 0;
}