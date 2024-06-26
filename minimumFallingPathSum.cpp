int tabulation(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s = matrix[i][j] + dp[i - 1][j];
            int ld = matrix[i][j];
            if (j > 0)
            {

                ld += dp[i - 1][j - 1];
            }
            else
            {
                ld += 1e9;
            }
            int rd = matrix[i][j];
            if (j < n - 1)
            {

                rd += dp[i - 1][j + 1];
            }
            else
            {
                rd += 1e9;
            }
            dp[i][j] = min(s, min(ld, rd));
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    return ans;
}
int helper(vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
{
    if (m < 0 || m >= matrix.size())
    {
        return 1e9;
    }
    if (n == 0)
    {
        return matrix[0][m];
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    int s = matrix[n][m] + helper(matrix, n - 1, m, dp);
    int left = matrix[n][m] + helper(matrix, n - 1, m - 1, dp);
    int right = matrix[n][m] + helper(matrix, n - 1, m + 1, dp);
    return dp[n][m] = min(s, min(left, right));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    // int n = matrix.size();

    // int ans = INT_MAX;
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // for(int i = 0; i < n; i++){

    //     ans = min( ans,helper(matrix,n-1,i,dp));
    // }
    // return ans;

    return tabulation(matrix);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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

    cout << minFallingPathSum(grid) << "\n";
}