#include <bits/stdc++.h>
using namespace std;
string read()
{
    int k;
    string s = "", str = "";
    char ch;
    while (cin.peek() != '\n')
    {
        cin >> ch;
        if (ch == '[')
        {
            cin >> k;
            str = read();
            while (k--)
            {
                s += str;
            }
        }
        else if (ch == ']')
        {
            return s;
        }
        else
        {
            s += ch;
        }
    }
    return s;
}
int main()
{
    cout << read();
    return 0;
}