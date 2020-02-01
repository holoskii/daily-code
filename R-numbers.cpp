/*
https://www.spoj.com/problems/ITRIX12E/
*/

#include <bits/stdc++.h>
using namespace std ;
#define MOD 1000000007

typedef long long ll;
typedef vector < vector < ll > > matrix ;

matrix mul(matrix A , matrix B){
    matrix C(11, vector < ll >(11)) ;

    for (int i = 1; i < 11; ++i)
        for (int j = 1; j < 11; ++j)
            for (int k = 1; k < 11; ++k)
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;

    return C;
}

matrix pow(matrix A ,int p) {
    if(p <= 1) return A;
    matrix res = pow(A, p / 2);

    res = mul(res, res);
    if (p % 2 != 0)
        res = mul(res, A);

    return res ;
}

bool isPrime(int n) {
    int lim = (int)sqrt(n + 1) ;
    for(int i = 2; i <= lim; ++i)
        if(n % i == 0) return false ;
    return true ;
}

int main() {
    freopen ("input.txt", "r", stdin);

    matrix A(11, vector<ll>(11));
    vector <ll> base = {0, 4, 4, 4, 3, 4, 3, 3, 2, 3, 3};

    for (int i = 1; i < 11; ++i)
        A[1][i] = 1;

    for (int i = 2; i < 11; ++i)
        for (int j = 2; j < 11; ++j)
            if(isPrime(i-1+j-1)) A[i][j] = 1 ;

    int t, n;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d" ,&n);

        matrix res = pow(A ,n-1);

        ll ans = 0LL ;
        for (int i = 1; i < 11; ++i)
            ans = (ans + ((res[1][i] % MOD) * base[i]) % MOD) % MOD;
        printf("%lld\n", ans);
    }
    return 0 ;
}
