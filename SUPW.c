"https://www.codechef.com/ZCOPRAC/problems/ZCO14002"
#include <stdio.h>
#define MIN(a,b) ((a) < (b)  ? (a) : (b) )
#define MIN_THREE(a,b,c) MIN(MIN(a,b),c)

int main ()
{
    int n;
    scanf("%d",&n);
    int a[200005];
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 3; i < n; ++i)
        a[i] += MIN_THREE(a[i - 1], a[i - 2], a[i - 3]);
    printf ("%d", MIN_THREE(a[n - 1], a[n - 2], a[n - 3]));
    return 0;
}
