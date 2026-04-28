#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    if(!(cin>>Q)) return 0;
    // 定义哈希表：键为姓名(string)，值为分数(long long)
    unordered_map<string, ll> sys;
    while(Q--){
    	int op;
    	cin>>op;
    	if(op==1){  //插入与修改
    		string name;
    		ll score;
    		cin>>name>>score;
    		sys[name]=score;   //如果存在则覆盖更新，不存在则插入
    		cout << "OK\n";    // 用 \n 替代 endl，避免频繁刷新缓冲区	
		}else if(op==2){  //查询
			string name;
			cin>>name;
			auto it=sys.find(name);
			if(it!=sys.end()){
				cout << it->second << "\n"; // it->second 获取对应的成绩
			}else {
                cout << "Not found\n";
            }
			
		}else if (op == 3) {
            string name;
            cin >> name;
            // erase 方法在 unordered_map 中会返回成功删除的元素个数（0 或 1）
            if (sys.erase(name)) {
                cout << "Deleted successfully\n";
            } else {
                cout << "Not found\n";
            }
            
        } else if (op == 4) {
            cout << sys.size() << "\n"; // 直接输出哈希表当前大小
        }
	}
	return 0;
}