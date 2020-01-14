/*
https://www.codechef.com/INOIPRAC/problems/INOI1202/
*/
#include <stdio.h>
#define MAX 200005

int i, n;
int a[MAX], inc[MAX], dec[MAX];

int max (int a, int b){return a > b ? a : b;}

int main()
{
	scanf ("%d", &n);

    for (i = 0; i < n; ++i)
    {
        scanf ("%d", a + i);
        a[i] += i;
    }

    inc[0] = a[0];
    for (i = 1; i < n; ++i)
        inc[i] = max(inc[i - 1], a[i]);

    dec[n - 1] = a[n - 1];
    for (i = n - 2; i >= 0; --i)
        dec[i] = max(dec[i + 1], a[i]);

    for (i = n - 1; i >= 0; --i)
        printf ("%d ", max(inc[i] + n - i, dec[i + 1] - i));
	return 0;
}
