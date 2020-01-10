/*
https://www.spoj.com/problems/BORW/
*/

#include <stdio.h>
#include <string.h>
#define N 110

int i, n, t, ans;
int a[N];
int d[N][N][N];

int max (int a, int b)
{
    return a > b ? a : b;
}
// inc - last element of increasing sequence, dec - last of decreasing, pos - current element
int solve (int inc, int dec, int pos)
{
    if (pos == n + 1) return 0;

    if (d[inc][dec][pos] != -1)
        return d[inc][dec][pos];

    d[inc][dec][pos] = solve (inc, dec, pos + 1);

    if (inc == 0)
        d[inc][dec][pos] = max (d[inc][dec][pos], 1 + solve (pos, dec, pos + 1));
    if (dec == 0)
        d[inc][dec][pos] = max (d[inc][dec][pos], 1 + solve (inc, pos, pos + 1));

    if (a[pos] > a[inc]) d[inc][dec][pos] = max (d[inc][dec][pos], 1 + solve (pos, dec, pos + 1));
    if (a[pos] < a[dec]) d[inc][dec][pos] = max (d[inc][dec][pos], 1 + solve (inc, pos, pos + 1));

    return d[inc][dec][pos] = d[inc][dec][pos];
}

int main()
{
    while (1)
    {
        scanf ("%d", &n);
        if (n == -1) return 0;
        for (i = 1; i <= n; ++i)
            scanf ("%d", a + i);
        memset (d, -1, sizeof (d));
        printf ("%d\n", n - solve (0, 0, 1));
    }
    return 0;
}
