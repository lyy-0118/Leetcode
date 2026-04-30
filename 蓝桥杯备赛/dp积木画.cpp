#include <stdio.h>
const int mod = 1e9+7,N = 1e7;
int main()
{
    int f[N]={0,1,2,5};
    int n;
    scanf("%d",&n);
    for(int i=4;i<=n;++i)
        f[i] = (2*f[i-1]%mod+f[i-3]%mod)%mod;
    printf("%d",f[n]);
    return 0;
}
