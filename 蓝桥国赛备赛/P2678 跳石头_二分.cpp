#include <bits/stdc++.h>
using namespace std;

//本题解法：
//二分枚举最短跳跃距离 d
//如果当前d 满足移走石头<=M 则继续枚举更大的d
//如果当前d 移走石头>M 说明当前d不可行 要枚举更小的d
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int L, N, M;
    cin >> L >> N >> M;
    vector<int> pos(N + 2);
    pos[0] = 0;       // 起点
    pos[N + 1] = L;   // 终点
    for (int i = 1; i <= N; i++) {
        cin >> pos[i];
    }
    // 判断是否能让最短跳跃距离至少为 d
    auto check=[&](int d){
    	int last = 0;    // 上一个保留的石头下标
        int cnt = 0;     // 移走石头数量
        for (int i = 1; i <= N + 1; i++) {
            if (pos[i] - pos[last] < d) {
                // 距离不够，移走当前石头
                cnt++;
            } else {
                // 距离够，保留当前石头
                last = i;
            }
        }
        return cnt <= M;
	};
	//开始二分枚举 从1~L枚举
	int left = 1, right = L;
    int ans = 0;
	while (left <= right) {
		int mid = left+(right-left)/2;
	 	if(check(mid)){
	 		ans=mid;
	 		left=mid+1;
		}else{
			right=mid-1;
		}
	}
	cout << ans << '\n';
	return 0;
}