/*
https://www.spoj.com/problems/BAT2/
*/
#include <stdio.h>
#include <string.h>
#define N 110

int i, n, t;
int a[N];
int d[N][N][N];

int max (int a, int b)
{
    return a > b ? a : b;
}
int solve (int inc, int dec, int pos)
{
    if (pos == n + 1) return 0;

    if (d[inc][dec][pos] != -1)
        return d[inc][dec][pos];

    d[inc][dec][pos] = solve (inc, dec, pos + 1);

    if (inc == 0) d[inc][dec][pos] = max (d[inc][dec][pos], 1 + solve (pos, dec, pos + 1));
    if (dec == 0) d[inc][dec][pos] = max (d[inc][dec][pos], 1 + solve (inc, pos, pos + 1));

    if (a[pos] > a[inc]) d[inc][dec][pos] = max (d[inc][dec][pos], 1 + solve (pos, dec, pos + 1));
    if (a[pos] < a[dec]) d[inc][dec][pos] = max (d[inc][dec][pos], 1 + solve (inc, pos, pos + 1));

    return d[inc][dec][pos] = d[inc][dec][pos];
}

int main()
{
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &n);
        for (i = 1; i <= n; ++i)
            scanf ("%d", a + i);
        memset (d, -1, sizeof (d));
        printf ("%d\n", solve (0, 0, 1));
    }
    return 0;
}
