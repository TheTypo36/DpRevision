#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int bestApproach(vector<vector<int>> &a, int m, int n)
{
    if (a[0][0] == 1 || a[m - 1][n - 1] == 1)
    {
        return 0;
    }
    vector<int> prev(n, 0);
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
            if (a[i][j] == 1)
            {
                temp[j] = 0;
                continue;
            }
            int left = 0, up = 0;

            if (i > 0)
            {
                up = prev[j];
            }
            if (j > 0)
            {
                left = temp[j - 1];
            }
            temp[j] = (left % mod + up % mod) % mod;
        }
        prev = temp;
    }

    return prev[n - 1];
}
int tabulation(vector<vector<int>> &OG, int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if (OG[0][0] == -1 || OG[m - 1][n - 1] == -1)
    {
        return 0;
    }
    // dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if (OG[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            int left = 0, up = 0;

            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }
            dp[i][j] = (left % mod + up % mod) % mod;
        }
    }
    // for(int i = 0; i < m ; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[m - 1][n - 1];
}
int mazeObstacles(vector<vector<int>> &mat, int m, int n)
{
    // Write your code here
    return tabulation(mat, m, n);
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
        int m, n;
        cin >> m >> n;
        vector<vector<int>> arr(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << bestApproach(arr, m, n) << "\n";
    }
}