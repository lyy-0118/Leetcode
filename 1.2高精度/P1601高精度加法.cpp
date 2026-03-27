#include <bits/stdc++.h>
using namespace std;

string add(string a,string b) {
	string ret;
	int n=a.size()-1,m=b.size()-1;
	int carry=0;
	while(n>=0||m>=0||carry) {
		int x=0,y=0;
		//转成数字
		if(n>=0) x=a[n]-'0';
		if(m>=0) y=b[m]-'0';
		int sum=x+y+carry;
		ret+=char(sum%10+'0');
		carry=sum/10;
		n--;
		m--;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1,s2;
	cin>>s1>>s2;
	cout<<add(s1,s2);
	return 0;
}