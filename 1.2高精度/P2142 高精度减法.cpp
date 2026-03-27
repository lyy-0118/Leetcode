#include<bits/stdc++.h>
using namespace std;
// 判断 a 是否大于等于 b
bool geq(string a,string b){
	if (a.size() != b.size()) return a.size() > b.size();
    return a >= b;
}
// 计算 a - b，要求 a >= b
string sub(string a,string b){
	//逆序求减法
	reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ret;
    int borrow=0; //借位
    for(int i=0;i<(int)a.size();i++){
    	int x=a[i]-'0';
    	int y=(i<(int)b.size()?b[i]-'0':0);
    	x-=borrow;
    	if(x<y){
    		x+=10;
    		borrow=1; //借位
		}else{
			borrow=0;
		}
		ret+=(char)(x-y+'0');
	}
	// 去掉前导零
    while (ret.size() > 1 && ret.back() == '0') ret.pop_back();
    reverse(ret.begin(), ret.end());
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string a,b;
	cin>>a>>b;
	if (geq(a, b)) {
        cout << sub(a, b) << '\n';
    } else { //a<b 用b减a
        cout << "-" << sub(b, a) << '\n';
    }
	return 0;
}