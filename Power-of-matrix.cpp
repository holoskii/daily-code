/*
https://www.spoj.com/problems/MPOW/
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define N 50

void mult (int n, ll a[N][N], ll b[N][N])
{
    ll r[N][N];
    memset (r, 0, sizeof (r));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
            {
                r[i][j] += a[i][k] * b[k][j] % MOD;
                r[i][j] %= MOD;
            }


    memcpy (a, r, sizeof (r));
}

void power (int n, ll a[N][N], int p)
{
    ll m[N][N];
    memcpy (m, a, sizeof (m));
    if (p == 1) return;
    power (n, a, p / 2);
    mult (n, a, a);
    if (p % 2 != 0)
        mult (n, a, m);
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    ll a[N][N];
    int t; scanf ("%d", &t);
    while (t--)
    {
        int n, m;
        scanf ("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf ("%lld", &a[i][j]);

        power (n, a, m);

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j)
                printf ("%lld ", a[i][j]);
            printf ("\n");
        }

    }
    return 0;
}
