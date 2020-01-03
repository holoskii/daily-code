/*https://www.spoj.com/problems/ALTSEQ/*/
#include <stdio.h>
#include <stdlib.h>
int a[5003], d[5003];

int max (int a, int b) {
    return a > b ? a : b;
}
int main(){
    //freopen ("input.txt", "r", stdin);
    int n, i, j;
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d", a + i);
        d[i] = 1;
    }


    for (i = 1; i < n; ++i)
        for (j = 0; j < i; ++j)
            if (((a[j] > 0 && a[i] < 0) || (a[j] < 0 && a[i] > 0))
                && abs(a[j]) < abs(a[i]))
                d[i] = max (d[i], d[j] + 1);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max (ans, d[i]);
    printf ("%d\n", ans);
    return 0;
    /*
    printf ("%d\n", n);
    for (int i = 0; i < n; ++i)
        printf ("%3d ", a[i]);
    printf ("\n");
    for (int i = 0; i < n; ++i)
        printf ("%3d ", d[i]);
    printf ("\n");
    */
}
