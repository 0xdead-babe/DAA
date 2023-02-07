#include <iostream>

using namespace std;

#define MAX 100

int DP[MAX][MAX];

int editDistance(string x, string y, int xLength, int yLength)
{
    for (int i = 0; i <= xLength; i++)
    {
        for (int j = 0; j <= yLength; j++)
        {
            // initalization
            if (i == 0)
                DP[i][j] = j;
            else if (j == 0)
                DP[i][j] = i;

            else if (x[i - 1] == y[j - 1])
                DP[i][j] = DP[i - 1][j - 1];

            else
                DP[i][j] = 1 + min(DP[i][j - 1], min(DP[i - 1][j], DP[i - 1][j - 1]));
        }
    }

    return DP[xLength][yLength];
}

int main()
{
    string x, y;
    cin >> x >> y;
    cout << editDistance(x, y, x.length(), y.length());
    return 0;
}