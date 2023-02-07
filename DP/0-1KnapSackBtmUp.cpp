#include <iostream>
#include <cstring>

using namespace std;

#define MAX 100

// global variable for wt and their associated profit
int WT[MAX];
int VAL[MAX];
// matrix to keep track of sub problems
int DP[MAX][MAX];

int knapSack(int n, int w)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            // initialization
            if (i == 0 || j == 0)
                DP[i][j] = 0;

            else if (WT[i - 1] > j)
                DP[i][j] = DP[i - 1][j];

            else
                DP[i][j] = max(VAL[i - 1] + DP[i - 1][j - WT[i - 1]], DP[i - 1][j]);
        }
    }

    return DP[n][w];
}

int main()
{
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> VAL[i] >> WT[i];
    cout << knapSack(n, W) << endl;
    return 0;
}