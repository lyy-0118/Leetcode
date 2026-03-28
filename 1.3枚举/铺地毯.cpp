#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N],b[N],g[N],k[N]; //a\b存坐标，g存x轴方向长度，k存y轴方向长度

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n=0,x,y,flag=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i]>>g[i]>>k[i];
	}
	cin>>x>>y;
	for(int i=n;i>0;i--){ //从后向前枚举
		if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i]){
			cout<<i;
			flag=1;
			break;
		}
	}
	if(!flag) cout<<-1;
    return 0;
}