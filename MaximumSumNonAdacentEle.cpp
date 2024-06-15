#include <bits/stdc++.h>
using namespace std;

int bestApproach(vector<int> &nums)
{
    int a = 0;
    int b = nums[0];
    int c = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        c = max(b, a + nums[i]);
        a = b;
        b = c;
    }
    return c;
}
int bottomUp(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], (dp[n - 2] + nums[i - 1]));
    }
    return dp[n];
}
int recursionToDown(vector<int> &nums, vector<int> &dp, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[n];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int recur1 = recursionToDown(nums, dp, n - 1);
    int recur2 = recursionToDown(nums, dp, n - 2) + nums[n];

    return dp[n] = max(recur1, recur2);
}
int recursion(vector<int> &nums, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[n];
    }

    int recur1 = recursion(nums, n - 1);
    int recur2 = recursion(nums, n - 2) + nums[n];

    return max(recur1, recur2);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return recursionToDown(nums, dp, n - 1);
    // return recursion(nums, n - 1);
}
int main()
{
    int houses;
    scanf("%d", &houses);
    vector<int> money(houses);

    for (auto &x : money)
        scanf("%d", &x);

    // printf("%d\n", rob(money));
    printf("%d\n", bottomUp(money));
    return 0;
}