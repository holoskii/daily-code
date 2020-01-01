#include <stdio.h>
int d[1000005],p[1000005],a[1000005];

int max(int a,int b)
{
	return a > b ? a : b;
}
int main()
{
    int n, k;
    scanf ("%d%d", &n, &k);
    --k;
    for (int i = 0; i < n; ++i)
        scanf ("%d", a + i);

    d[k + 1] = a[k + 1];
    for (int i = k + 2; i < n; ++i)
        d[i] = a[i] + max (d[i - 1], d[i - 2]);

    p[1] = a[0];
    for (int i = 2; i < n; ++i)
        p[i] = max (a[i - 1] + p[i - 1], a[i - 2] + p[i - 2]);

    int ans = d[k] + p[k];
    for (int i = k + 1; i < n; ++i)
        ans = max (ans, d[i] + p[i]);
    printf("%d\n",ans );
    return 0;
}
