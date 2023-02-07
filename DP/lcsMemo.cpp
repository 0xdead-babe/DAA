#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

int DP[MAX][MAX];

int lcs(string x, string y, int xLength, int yLength)
{
    // base condition
    // check if any of the string is of length 0
    if (xLength == 0 || yLength == 0)
        return 0;
    // check if solution to recursion is already there
    if (DP[xLength][yLength] != -1)
        return DP[xLength][yLength];

    if (x[xLength - 1] == y[yLength - 1])
        return DP[xLength][yLength] = 1 + lcs(x, y, xLength - 1, yLength - 1);
    else
        return DP[xLength][yLength] = max(lcs(x, y, xLength - 1, yLength), lcs(x, y, xLength, yLength - 1));
}

int main()
{
    string x, y;
    cin >> x >> y;
    memset(DP, -1, sizeof(DP));
    cout << lcs(x, y, x.length(), y.length());
    return 0;
}