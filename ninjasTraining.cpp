#include <bits/stdc++.h>
using namespace std;

int recursion(int n, vector<vector<int>> &points, vector<bool> &check)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return max(points[0][0], max(points[0][1], points[0][2]));
    }
    int recur1 = 0, recur2 = 0, recur3 = 0;
    if (check[0] == false)
    {
        check[0] = true;
        recur1 = points[n - 1][0] + recursion(n - 1, points, check);
    }
    else
    {

        check[0] = false;
    }
    if (check[1] == false)
    {
        check[1] = true;
        recur2 = points[n - 1][1] + recursion(n - 1, points, check);
    }
    else
    {

        check[1] = false;
    }
    if (check[2] == false)
    {
        check[2] = true;
        recur3 = points[n - 1][2] + recursion(n - 1, points, check);
    }
    else
    {

        check[2] = false;
    }
    return max(recur1, max(recur1, recur2));
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<bool> check(3, false);
    return recursion(n, points, check);
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    scanf("%d", &testcase);
    while (testcase--)
    {
        int n;
        scanf("%d", &n);
        vector<vector<int>> a(3, vector<int>(n, 0));

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        printf("%d", ninjaTraining(n, a));
    }
}