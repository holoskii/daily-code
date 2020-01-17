/*
https://www.codechef.com/INOIPRAC/problems/INOI1601
*/
#include <bits/stdc++.h>
#define N 100005
using namespace std;

typedef struct emp {
    int i, p, w;
} emp;

int n, i, ans;
int w[N];
emp a[N];
vector <emp> t[N];

queue <emp> q1;
queue <emp> q;
emp tt;

int main()
{
    freopen ("input.txt", "r", stdin);
    scanf ("%d", &n);
    for (i = 1; i <= n; ++i){
        a[i].i = i;
        scanf ("%d", &a[i].w);
    }

    for (i = 1; i <= n; ++i){
        scanf ("%d", &a[i].p);
        if (a[i].p == -1) a[i].p = 0;
        t[a[i].p].push_back(a[i]);
    }

    q.push(*t[0].begin());
    while (!q.empty())
    {
        tt = q.front();
        q.pop();
        q1.push(tt);

        vector <emp>::iterator it = t[tt.i].begin();
        for (;it != t[tt.i].end(); it++)
            q.push(*it);
    }

    ans = 0;
    while (!q1.empty())
    {
        tt = q1.front();
        q1.pop();
        if (tt.p != 0)
            w[tt.i] = max (w[tt.p], tt.w);
        else
            w[tt.i] = tt.w;
        ans = max (ans, w[tt.i] - tt.w);
    }

    printf ("%d", ans);
    return 0;
}
