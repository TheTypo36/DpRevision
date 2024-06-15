#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// time: o(n) space: o(1)
ll bestApproach(ll n)
{
    ll a = 0;
    ll b = 1;
    ll c = 0;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
// tabular form time_complexity:O(n)  , space_complexity: O(n);
ll fibBottomUp(ll n)
{
    vector<ll> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// memoisation time_complexity:O(n)  , space_complexity: O(n);
ll fibTopDown(ll n, vector<ll> &dp)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        return dp[n] = fibTopDown(n - 1, dp) + fibTopDown(n - 2, dp);
    }
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    cout << fibTopDown(n, dp) << endl;
    cout << fibBottomUp(n) << endl;
    cout << bestApproach(n) << endl;
}