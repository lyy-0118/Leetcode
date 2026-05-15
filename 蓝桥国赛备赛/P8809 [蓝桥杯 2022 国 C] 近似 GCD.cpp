#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];
int f[N];
int s[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long ans=0;
	int n,g;
	cin>>n>>g;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%g!=0) f[i]=1;
		s[i]=s[i-1]+f[i];
	}
	for(int i=1,j=2;j<=n;j++){
		while(i<j&&s[j]-s[i-1]>1){
			i++;
		}
		ans+=j-i;
	}
	cout<<ans;
	return 0;
}