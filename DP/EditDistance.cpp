// memoized version code
#include <iostream>
#include <cstring>

using namespace std;
#define MAX 100

int DP[MAX][MAX];

int editDistance(string x, string y, int xLength, int yLength)
{
    // base condition
    // yLength number of insertion required

    if (xLength == 0)
        return yLength;
    // yLength number of deletion required
    if (yLength == 0)
        return  xLength;

    if (DP[xLength][yLength] != -1)
        return DP[xLength][yLength];

    // if two characters are same not need to replace, insert or delete
    if (x[xLength - 1] == y[yLength - 1])
        return DP[xLength][yLength] = editDistance(x, y, xLength - 1, yLength - 1);

    // insertion f(i, j-1)
    // deletion f(i-1, j)
    // replace  f(i-1, j-1)

    return DP[xLength][yLength] = 1 + min(editDistance(x, y, xLength, yLength - 1), min(editDistance(x, y, xLength - 1, yLength), editDistance(x, y, xLength - 1, yLength - 1)));
}

int main()
{
    string x, y;
    cin >> x >> y;
    memset(DP, -1, sizeof(DP));
    cout << editDistance(x, y, x.length(), y.length());
    return 0;
}
