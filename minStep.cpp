#include <bits/stdc++.h>
using namespace std;

int minStep(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
        return 1;

    return minStep(n - 1) + minStep(n - 2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    //cout << minTopDown(n, dp) << "\n";
    cout << minStep(n) << "\n";
}