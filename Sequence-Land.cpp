/*
https://www.codechef.com/INOIPRAC/problems/INOI1302
*/
#include <bits/stdc++.h>
using namespace std;

int n, k, i, t, j, c, ans;
int ii, jj, kk;
int l[300], dp[300];
int a[300][300];

int main()
{
    freopen ("input.txt", "r", stdin);

    scanf ("%d%d", &n, &k);
    for (i = 0; i < n; ++i)
    {
        scanf ("%d", &t);
        for (j = 0; j < t; ++j)
            scanf ("%d", *(a + i) + j);
        sort (a[i], a[i] + t);
        l[i] = t;
    }

    vector <int> d[n];
    for (i = 0; i < n; ++i)
        for (j = i + 1; j < n; ++j)
        {
            kk = 0, ii = 0, jj = 0;
            while (ii < l[i] && jj < l[j])
                if (a[i][ii] == a[j][jj])
                    ++kk, ++ii, ++jj;
                else if (a[i][ii] < a[j][jj])
                    ++ii;
                else
                    ++jj;

            if (kk >= k)
            {
                d[i].push_back(j);
                d[j].push_back(i);
            }
        }

    queue<int> q;
    q.push(0);
    while (!q.empty()){
        c = q.front(), q.pop();
        vector <int>::iterator it = d[c].begin();
        while (it != d[c].end())
        {
            if (dp[*it] == 0) q.push(*it);
            ++it;
        }
        dp[c] = 1;
    }

    ans = 0;
    for (i = 0; i < n; ++i)
        ans += dp[i];
    printf ("%d", ans);

    return 0;
}
