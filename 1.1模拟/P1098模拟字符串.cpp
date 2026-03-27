#include<bits/stdc++.h>
using namespace std;

int p1,p2,p3;
string s,ret;

bool isNumber(const char ch){
	return ch>='0'&&ch<='9';
}
bool isLetter(const char ch){
	return ch>='a'&&ch<='z';
}
void add(char left,char right){
	string t;
	//遍历中间的字符
	for(char ch = left + 1; ch < right; ch++){
		char tmp=ch;
		//处理p1
		if(p1==2&&isLetter(tmp)) tmp -= 32; // 小写变大写
		else if(p1 == 3) tmp = '*'; // 变成星号
		
		//处理p2
        for(int i = 0; i < p2; i++)
        {
            t += tmp;
        }
        
	}
	// 处理 p3
   	if(p3 == 2) reverse(t.begin(), t.end());
   		
   	ret += t;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin>>p1>>p2>>p3>>s;
	for(int i=0;i<s.size();i++){
		//如果当前字符不是减号，或者减号出现在最前面/最后面，那么它不能作为展开符号，直接加入结果。
		if(s[i]!='-'||i==0||i==s.size()-1){
			ret+=s[i];
		}else{ //当前字符是中间位置的 -
			char left=s[i-1],right=s[i+1];
			//可以展开的两种情况：
			//1.左右都是数字，并且右边比左边大 2.左右都是小写字母，并且右边比左边大
			if((isNumber(left) && isNumber(right) && right > left) ||
			   (isLetter(left) && isLetter(right) && right > left)){
				add(left,right);
			}else{
				ret+='-';
			}
		}
	}
	cout<<ret<<endl;
	
	return 0;
}