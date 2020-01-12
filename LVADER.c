/*
https://www.spoj.com/problems/LVADER/
*/
#include <stdio.h>
#define ll long long
#define MOD 1000000007

ll fac[200005];

ll min (ll a, ll b){
    return a < b ? a : b;
}
ll power(ll x, ll y){
    ll res = 1;
    x = x % MOD;
    while (y > 0){
        if (y % 2 == 1)
            res = (res * x) % MOD;
        y = y / 2;
        x = (x * x) % MOD;
    }
    return res;
}
ll inverse(ll n){
    return power(n, MOD - 2);
}
ll nCr(ll n, ll r){
    return (fac[n] * inverse(fac[r]) % MOD * inverse(fac[n - r]) % MOD) % MOD;
}

int i, t, x1, y1, x2, y2;
ll k, a, n, m, ans;

int main()
{
    freopen ("input.txt", "r", stdin);

    fac[0] = 1;
    for (i = 1; i <= 200001; ++i)
        fac[i] = (fac[i - 1] * i) % MOD;

    scanf ("%d", &t);
    for (i = 0; i < t; ++i)
    {
        scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
        m = (ll)(x2 - x1);
        n = (ll)(y2 - y1);
        ans = 0;
        for (a = 0; a <= min(m, n); ++a)
        {
            k = (nCr(m + n - a, m)) % MOD;
            k = (k * nCr(m, a)) % MOD;
            ans = (ans + k) % MOD;
        }
        printf ("Case %d: %d\n", i + 1, (int) ans);
    }
    return 0;
}
