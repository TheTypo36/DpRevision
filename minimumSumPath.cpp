#include <bits/stdc++.h>
using namespace std;

int bestApproach(vector<vector<int>> &grid, int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0) for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = grid[] continue;
            }
            int left = INT_MAX, up = INT_MAX;
            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }
            dp[i][j] = grid[i][j] + min(left, up);
        }
    }
}
int tabulation(vector<vector<int>> &grid, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = grid[0][0];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int left = INT_MAX, up = INT_MAX;
            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }
            dp[i][j] = grid[i][j] + min(left, up);
        }
    }
    // for(int i = 0; i <= m; i++){
    //     for(int j=0; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout <<"\n";
    // }
    return dp[m][n];
}
int memoization(vector<vector<int>> &grid, int r, int c, int m, int n, vector<vector<int>> &dp)
{

    if (r == m && c == n)
    {
        return grid[m][n];
    }
    if (r > m || c > n)
    {
        return INT_MAX;
    }
    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }
    int bottom = memoization(grid, r + 1, c, m, n, dp);
    int right = memoization(grid, r, c + 1, m, n, dp);
    return dp[r][c] = grid[r][c] + min(right, bottom);
}
int minPathSumHelper(vector<vector<int>> &grid, int r, int c, int m, int n)
{
    if (r == m && c == n)
    {
        return grid[m][n];
    }
    if (r > m || c > n)
    {
        return INT_MAX;
    }
    int bottom = minPathSumHelper(grid, r + 1, c, m, n);
    int right = minPathSumHelper(grid, r, c + 1, m, n);
    return grid[r][c] + min(right, bottom);
}
int minPathSum(vector<vector<int>> &grid)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m = grid.size();
    int n = grid[0].size();
    // vector<vector<int>> dp(m,vector<int>(n,-1));
    return tabulation(grid, m - 1, n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--)
    {

        int m;
        int n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        cout << minPathSum(grid) << "\n";
    }
}