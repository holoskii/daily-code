/*https://www.codechef.com/ZCOPRAC/problems/ZCO12004*/
#include <stdio.h>
#include <stdlib.h>
int min (int a, int b)
{
    return a < b ? a : b;
}
int main ()
{
    //freopen ("input.txt", "r", stdin);
    int n;
    scanf ("%d", &n);
    int *a = (int*) malloc (n * sizeof (int));
    int *d = (int*) malloc (n * sizeof (int));
    for (int i = 0; i < n; ++i)
        scanf ("%d", a + i);
    d[0] = a[0];
    d[1] = a[0] + a[1];
    for (int i = 2; i < n; ++i)
        d[i] = a[i] + min (d[i - 1], d[i - 2]);
    int ans = min (d[n - 1], d[n - 2]);
    d[0] = 2000000000;
    d[1] = a[1];
    for (int i = 2; i < n; ++i)
        d[i] = a[i] + min (d[i - 1], d[i - 2]);
    ans = min (ans, d[n - 1]);
    printf ("%d", ans);
    return 0;
}
