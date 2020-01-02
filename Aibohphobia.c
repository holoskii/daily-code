/*https://www.spoj.com/submit/AIBOHP/*/
#include <stdio.h>
#include <string.h>

char s[6103];
int a[6103][6103];

int min (int a, int b)
{
    return a < b ? a : b;
}

int main ()
{
    //freopen ("input.txt", "r", stdin);
    int i, j, d, n, t;
    scanf ("%d", &t);
    gets (s);
    for (i = 0; i < 6103; ++i) a[i][i] = 0;
    while (t--)
    {
        gets (s);
        n = strlen (s);
        for (d = 1; d < n; ++d)
            for (i = 0; (j = i + d) < n; ++i)
                a[i][j] = (s[i] == s[j]) ? a[i + 1][j - 1]
                                         : min (a[i + 1][j], a[i][j - 1]) + 1;
        printf ("%d\n", a[0][n - 1]);
    }
    return 0;
}
