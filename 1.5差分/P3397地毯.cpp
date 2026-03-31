#include <bits/stdc++.h>
using namespace std;

int n,m;
typedef long long LL;
LL f[1005][1005];

void add(int x1, int y1, int x2, int y2, LL k)
{
    f[x1][y1] += k; 
	f[x1][y2 + 1] -= k; 
	f[x2 + 1][y1] -= k; 
	f[x2 + 1][y2 + 1] += k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    	int x1,x2,y1,y2;
    	cin>>x1>>y1>>x2>>y2;
    	add(x1,y1,x2,y2,1);
	}
	// 利用前缀和还原出修改之后的数组
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + f[i][j];
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}