#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool checkValidString(string str)
{
    stack<int> open;
    stack<int> star;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            open.push(i);
        else if (str[i] == '*')
            star.push(i);
        else
        {
            if (!open.empty())
                open.pop();
            else if (!star.empty())
                star.pop();
            else
                return false;
        }
    }

    while (!open.empty())
    {
        // this if must be written first
        // otherwise it means that we are check for a element that might not have been present
        // so exception
        if (star.empty())
        {
            return false;
        }
        else if (open.top() < star.top())
        {
            star.pop();
            open.pop();
        }
        else
            return false;
    }
    return true;
}

int main(int args, char **argv)
{
    cout << (boolalpha) << checkValidString("*((*)") << endl;
    return 0;
}