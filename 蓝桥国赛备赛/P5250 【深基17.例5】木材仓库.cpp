#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;  //操作次数
	set<int> wood; //存储木材长度，自动排序且不重复
	while(n--){
		int op,len;
		cin>>op>>len;
		if(op==1){
			//进货
			if(wood.count(len)){
				cout << "Already Exist\n";
			}else{
				wood.insert(len);
			}
		}else{
			//出货
			if(wood.empty()){
				cout << "Empty\n";
                continue;
			}
			auto it=wood.lower_bound(len); //找到第一个 >=x 的位置
			//候选木材最多两个：这个位置的木材，以及它前一个较短的木材。
			//比较它们与 x 的距离，距离小的取出；若距离相等，取较短的。
			
			int ans;
			if (it == wood.begin()) {
                // 没有比 len 小的，只能取当前这个
                ans = *it;
            } else if (it == wood.end()) {
                // 所有木材都比 len 小，取最大的
                auto pre = prev(it);
                ans = *pre;
        	}else{
        		// 比较 it 和前一个元素
        		int len1=*prev(it),len2=*it;
        		
        		//距离小的取出
        		if(abs(len1-len)>abs(len2-len)){
        			ans=len2;
				}else {
					//距离相等时取较短的
					ans=len1;
				}
			}
			cout << ans << '\n';
            wood.erase(ans); // 取出木材
		}
	}
	return 0;
}