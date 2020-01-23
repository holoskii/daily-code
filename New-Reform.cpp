/*
https://codeforces.com/problemset/problem/659/
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, i, h, g, cur, vertices, edges, ans, ex;

int main()
{
    scanf ("%d%d", &n, &m);

    queue <int> q;
    bool vis[n + 5];
    vector <int> a[n + 5];
    vector <int> :: iterator it;
    memset (vis, 0, n + 5);

    for (i = 0; i < m; ++i)
    {
        scanf ("%d%d", &h, &g);
        a[h - 1].push_back(g - 1);
        a[g - 1].push_back(h - 1);
    }



    ex = 1;
    while (ex)
    {
        i = 0;
        while (i < n && vis[i] == 1) i++;
        if (i == n)
        {
            break;
            ex = 0;
        }

        q.push(i);
        vertices = 0;
        edges = 0;

        while (!q.empty())
        {
            cur = q.front(); q.pop();

            vis[cur] = 1;
            edges += a[cur].size();
            ++vertices;

            it = a[cur].begin();
            while (it != a[cur].end())
            {
                if (vis[*it] == 0)
                    q.push(*it);
                ++it;
            }
        }
        edges /= 2;
        if (edges + 1 <= vertices)
            ++ans;
    }

    printf ("%d", ans);
    return 0;
}
