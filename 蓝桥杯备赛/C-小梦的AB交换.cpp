#include<bits/stdc++.h>
using namespace std;
//计算错位数
int Cnt(const string &s,char start){
	int len=s.size(),ret=0;
	for(int i=0;i<len;i++){
		char cur;   //cur为ABABAB串当前i位置的字符
		if(i%2==0) cur=start;   //偶数位等于起始字符
		else cur=(start=='A'?'B':'A'); //奇数位则相反
		
		if(cur!=s[i]) ret++;
	}
	return ret/2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		string s;
		cin>>s;
		int cnt=min(Cnt(s,'A'),Cnt(s,'B'));
		cout<<cnt<<'\n';
	}
	return 0;
}