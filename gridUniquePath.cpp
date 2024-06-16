#include <bits/stdc++.h>
using namespace std;

int bestApproach(int m, int n)
{
    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
            {
                up = dp[j];
            }
            if (j > 0)
            {
                left = temp[j - 1];
            }
            temp[j] = left + up;
        }
        dp = temp;
    }
    return dp[n - 1];
}
int tabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int left = 0, right = 0;
                if (i > 0)
                {
                    left = dp[i - 1][j];
                }
                if (j > 0)
                {
                    right = dp[i][j - 1];
                }
                dp[i][j] = left + right;
            }
        }
    }
    return dp[m - 1][n - 1];
}
// time complexity -> 
int helper(int row, int col, int m, int n, vector<vector<int>> &dp)
{
    if (row == m && col == n)
    {
        return 1;
    }
    if (row > m || col > n)
    {
        return 0;
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    int r1 = helper(row + 1, col, m, n, dp);
    int r2 = helper(row, col + 1, m, n, dp);

    return dp[row][col] = r1 + r2;
}

int uniquePaths(int m, int n)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    // return helper(1,1,m,n,dp);
    return bestApproach(m, n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    cout << uniquePaths(m, n);
}