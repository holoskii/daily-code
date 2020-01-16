/*
https://www.codechef.com/problems/PCYCLE
*/
#include <bits/stdc++.h>
#define N 1000
using namespace std;

int n, vn, i, cn, cur;
int a[N];
int b[2*N];
bool v[N];

int main()
{
    freopen ("input.txt", "r", stdin);
    scanf ("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf ("%d", a + i);
        --a[i];
    }

    vn = 0;
    cn = 0;
    while (vn - cn < n)
    {
        i = 0;
        while (i < n && v[i]) i++;
        if (i == n) break;
        cn++;
        cur = i;
        b[vn++] = cur;
        while (!v[cur])
        {
            v[cur] = 1;
            cur = a[cur];
            b[vn++] = cur;
        }
    }

    memset (v, 0, n);
    printf ("%d\n", cn);
    for (i = 0; i < vn; ++i)
    {
        printf ("%d ", b[i] + 1);
        if (v[b[i]] == 1)
            printf ("\n");
        v[b[i]] = 1;
    }

    return 0;
}
