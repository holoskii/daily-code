/*
https://www.spoj.com/problems/LAZYPROG/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct job{
    long int a;
    long int b;
    long long int d;
};
bool cmp1(job j1, job j2){
    if (j1.d == j2.d)
        return j1.a<j2.a;
    return  j1.d>j2.d ;
}
class cmp2{
    public :
        bool operator() (job j1,job j2){
        return  j1.a>j2.a;
    }
};

int main() {
    //freopen("input.txt","r",stdin);

    long long int time, deadline, next_deadline;

    int t, n, i;
    cin >> t;
    while (t--){
        cin >> n;
        vector<job> jobs (n);
        for (i = 0; i < n; ++i){
            cin >> jobs[i].a;
            cin >> jobs[i].b;
            cin >> jobs[i].d;
        }
        sort(begin(jobs), end(jobs), cmp1);
        priority_queue <job, vector<job>, cmp2> pq;


        i = 0;
        time = 0;

        while (i < n) {
            deadline = jobs[i].d;
            while (i < n && jobs[i].d == deadline) {
                pq.push(jobs[i]);
                ++i;
            }

            if (i >= n)
                next_deadline = 0;
            else
                next_deadline = jobs[i].d;

            time = deadline - next_deadline;
            while (time > 0) {
                if (pq.empty()){
                    break;
                }

                job j = pq.top();
                if (j.b <= time) {
                    time -= j.b;
                    pq.pop();
                } else {
                    j.b -= time;
                    time = 0;
                    pq.pop();
                    pq.push(j);
                }
            }
        }

        long double ans=0;
        while (!pq.empty()){
            job j = pq.top();
            ans += (long double) j.b / j.a;
            pq.pop();
        }
        printf("%.02Lf\n",ans);

    }
}
