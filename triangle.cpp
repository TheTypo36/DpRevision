#include <bits/stdc++.h>
using namespace std;

int bestApproach(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    vector<int> base(n, 0);
    for (int i = 0; i < n i++)
    {
        base[i] = triangle[n][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(n, 0);
        for (int j = i; j >= 0; j--)
        {
            int d = triangle[i][j] + base[j];
            int dg = triangle[i][j] + base[j + 1];

            temp[j] = min(d, dg);
        }
        base = temp;
    }
    return base[0];
}
int tabulation(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = grid[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            d = grid[i][j] + dp[i + 1][j];
            dg = grid[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(d, dg);
        }
    }
    return dp[0];
}
int memoization(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return triangle[n][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int d = memoization(triangle, i + 1, j + 1, n, dp);
    int down = memoization(triangle, i + 1, j, n, dp);

    return dp[i][j] = triangle[i][j] + min(d, down);
}
int helper(vector<vector<int>> &triangle, int i, int j, int n)
{
    if (i == n)
    {
        return triangle[n][j];
    }

    int d = helper(triangle, i + 1, j + 1, n);
    int down = helper(triangle, i + 1, j, n);

    return triangle[i][j] + min(d, down);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return memoization(triangle, 0, 0, n - 1, dp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
}