/*
https://www.codechef.com/problems/MARBLES
*/
#include <bits/stdc++.h>
using namespace std;

long long t, n, k, ans, d, i;
int main()
{
    freopen ("input.txt", "r", stdin);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        n--; k--;

        // ans = C(n, k)
        if (n - k < k)
            k = n - k;

        d = 1;
        ans = 1;
        for (i = n; i > n - k; --i)
        {
            ans *= i;
            if (d <= k && ans % d == 0)
                ans /= d++;
        }
        while (d <= k)
            ans /= d++;

        printf ("%lld\n", ans);
    }
    return 0;
}
