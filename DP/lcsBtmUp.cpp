#include <iostream>
using namespace std;

#define MAX 100

int DP[MAX][MAX];

int lcs(string x, string y, int xLength, int yLength)
{
    for (int i = 0; i <= xLength; i++)
    {
        for (int j = 0; j <= yLength; j++)
        {
            // initialization
            if (i == 0 || j == 0)
                DP[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
                DP[i][j] = 1 + DP[i - 1][j - 1];
            else
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
        }
    }

    return DP[xLength][yLength];
}

int main()
{
    string x, y;
    cin >> x >> y;
    cout << lcs(x, y, x.length(), y.length());
    return 0;
}