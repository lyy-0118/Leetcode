#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        string s;
        cin >> s;
        s = " " + s; // 转成 1 下标，方便处理

        long long ans = 0;

        int l = 1;
        while (l <= n) {
            int r = l;

            // 如果 s[r+1] == 'Z'，说明 r 和 r+1 被连接在同一块里
            while (r + 1 <= n && s[r + 1] == 'Z') {
                r++;
            }

            // 现在得到一个连通块 [l, r]
            // 统计整块变成全正 / 全负分别需要修改多少次
            long long costPos = 0; // 整块全正：需要修改 a[i] <= 0 的位置
            long long costNeg = 0; // 整块全负：需要修改 a[i] >= 0 的位置

            for (int i = l; i <= r; i++) {
                if (a[i] <= 0) costPos++;
                if (a[i] >= 0) costNeg++;
            }

            // 判断这一块是否被固定符号
            // 只有块的左端点 s[l] 可能是 '<' 或 '>' 来固定整块符号
            if (s[l] == '<') {
                // 整块必须为负
                ans += costNeg;
            } else if (s[l] == '>') {
                // 整块必须为正
                ans += costPos;
            } else {
                // 没有固定符号
                // 如果这块长度为 1，则完全自由，不需要修改
                // 例如 s[1]=='Z' 但 i=1 时没有任何约束
                if (l == r) {
                    ans += 0;
                } else {
                    // 长度 > 1，说明确实被 Z 约束成同号且非零
                    ans += min(costPos, costNeg);
                }
            }

            l = r + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
//下面的虽然可以过AC，但是会越界
//比如当s[0]=‘Z’,会越界访问a[-1]
////计算错位数
//int Cnt(vector<int>& a,const string& s){
//	int ret=0,len=s.size();
//	for(int i=0;i<len;i++){
//		char cur=s[i];
//		int num=a[i];
//		if(cur=='>'&&num<=0){
//			ret++;
//			a[i]=1;
//		}else if(cur=='<'&&num>=0){
//			ret++;
//			a[i]=-1;
//		}else if(cur=='Z'){
//			if(a[i-1]>0&&num<=0){
//				ret++;
//				a[i]=1;
//			}else if(a[i-1]<0&&num>=0){
//				ret++;
//				a[i]=-1;
//			}
//		}
//	}
//	return ret;
//}
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	
//	int t;
//	cin>>t;
//	while(t--){
//		int n;
//		cin>>n;
//		vector<int> a(n);
//		string s;
//		for(int i=0;i<n;i++){
//			cin>>a[i];
//		}
//		cin>>s;
//		
//		cout<<Cnt(a,s)<<'\n';
//	}
//	return 0;
//}

