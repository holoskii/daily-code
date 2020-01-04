/*https://www.codechef.com/INOIPRAC/problems/INOI1401*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 300
#define MOD 20011
int main()
{
    //freopen ("input.txt", "r", stdin);
    int n, m, l, c;
    scanf ("%d%d%d", &n, &m, &l);
    bool a[N][N];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf ("%d", &a[i][j]);
    int v[N][N];
    int h[N][N];
    memset (v, 0, sizeof (v));
    memset (h, 0, sizeof (h));
    v[0][0] = 1;
    h[0][0] = 1;
    //printf (" > 1\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            c = 1;

            while (i + c < n && c <= l && a[i + c][j])
            {
                v[i + c][j] = (v[i + c][j] + h[i][j]) % MOD;
                c++;
            }
            c = 1;
            while (j + c < m && c <= l && a[i][j + c])
            {
                h[i][j + c] = (h[i][j + c] + v[i][j]) % MOD;
                c++;
            }
            /*
            printf ("h:\n");
            for (int gi = 0; gi < n; ++gi){
                for (int gj = 0; gj < m; ++gj)
                    printf ("%d ", h[gi][gj]);
                printf ("\n");
            }
            printf ("f:\n");
            for (int gi = 0; gi < n; ++gi){
                for (int gj = 0; gj < m; ++gj)
                    printf ("%d ", v[gi][gj]);
                printf ("\n");
            }
            */
        }
    }

    /*
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j)
            printf ("%d ", a[i][j]);
        printf ("\n");
    }
    */
    printf("%d\n", (v[n - 1][m - 1] + h[n - 1][m - 1]) % MOD);
    return 0;
}
