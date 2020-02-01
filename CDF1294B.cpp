/*
https://codeforces.com/contest/1294/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int t, n, i, p, poss, j;
char s[2000];
int main()
{
    //freopen ("input.txt", "r", stdin);
    cin >> t;
    while (t--)
    {
        p = 0;
        poss = 1;
        cin >> n;
        pair <int, int> a[n];
        for (i = 0; i < n; ++i)
            cin >> a[i].first >> a[i].second;
        sort (a, a + n);

        for (i = 0; i < a[0].first; ++i) s[p++] = 'R';
        for (i = 0; i < a[0].second; ++i) s[p++] = 'U';
        pair <int, int> prev = a[0];

        for (i = 1; i < n; ++i)
        {
            if (a[i].first < prev.first || a[i].second < prev.second)
            {
                poss = 0;
                break;
            }
            for (j = prev.first; j < a[i].first; ++j) s[p++] = 'R';
            for (j = prev.second; j < a[i].second; ++j) s[p++] = 'U';
            prev = a[i];
        }

        s[p] = 0;
        if (poss == 1)
            printf ("YES\n%s\n", s);
        else
            printf ("NO\n");
    }
    return 0;
}
