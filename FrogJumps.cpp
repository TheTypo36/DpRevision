#include <bits/stdc++.h>
using namespace std;

int frogJum(vector<int> &a, int n)
{
    if (n <=1)
    {
        return 0;
    }
    int recurAns1 = frogJum(a, n - 1);
    int recurAns2 = frogJum(a, n - 2);

    return min((abs(a[n - 1] - a[n - 2]) + recurAns1), (abs(a[n - 1] - a[n - 3]) + recurAns2));
}
int main()
{
    

    int testcase;
    scanf("%d", &testcase);
    while (testcase--)
    {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        for (auto &x : a)
            scanf("%d", &x);

        printf("%d\n", frogJum(a, n));
    }
}