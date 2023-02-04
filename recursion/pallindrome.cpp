#include <bits/stdc++.h>
using namespace std;

bool checkPallin(string s, int i)
{
    if (i >= s.length() / 2)
        return true;
    if (s[i] != s[s.length() - i - 1])
        return false;
    return checkPallin(s, i + 1);
}

int main()
{
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << checkPallin(input, 0);
    return 0;
}