//密文搜索思路
//1.枚举字符串每个长度为8的子串，排序后加入哈希表中记录次数
//2.检查排序后的密码是否出现过，若出现过则加上次数
#include<bits/stdc++.h>
using namespace std;

int ans=0;

int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	int m=s.size();
	unordered_map<string,int> mp;
	for(int i=0;i+8<=m;i++){
		string t(s.begin()+i,s.begin()+i+8);
		sort(t.begin(),t.end());
		mp[t]++; //次数+1
	}
	
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		sort(str.begin(),str.end());
		if(mp.count(str)){
			ans+=mp[str];	
		}
	}
	cout<<ans<<endl;
	return 0;
}