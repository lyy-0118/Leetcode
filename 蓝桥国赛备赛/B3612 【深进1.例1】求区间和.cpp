#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> arr(n+1);
	vector<int> sum(n+1);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i]=sum[i-1]+arr[i];
	}
	int m;
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<"\n";
	}
	return 0;
}