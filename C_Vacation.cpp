#include <bits/stdc++.h>
using namespace std;

int tabulation(int n, vector<vector<int> > &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(point[0][1], point[       0][2]);
    dp[0][0] = max(point[0][1],point[0][2]);
    dp[0][0] = max(point[0][1],point[0][2]);
    dp[0][0] = max(point[0][1], point[0][2]);
}
int recursionDp(int n, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (last != i)
            {
                maxi = max(points[0][i], maxi);
            }
        }
        return maxi;
    }
    if (dp[n][last] != -1)
    {
        return dp[n][last];
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {

            maxi = max(maxi, points[n][i] + recursionDp(n - 1, points, i, dp));
        }
    }
    return dp[n][last] = maxi;
}
int recursion(int n, vector<vector<int>> &points, int check)
{

    if (n == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (check != i)
            {
                maxi = max(points[0][i], maxi);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != check)
        {

            maxi = max(maxi, points[n][i] + recursion(n, points, i));
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // return recursion(n-1, points, 3);
    return recursionDp(n - 1, points, 3, dp);
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    scanf("%d", &n);
    vector<vector<int>> a(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("%d", ninjaTraining(n, a));
}