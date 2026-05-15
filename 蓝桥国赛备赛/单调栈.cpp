//单调栈维护一个后缀最大值
//单调栈常用来解决这类问题：对于每个位置 i，找它左边或者右边第一个比它大/小的元素。
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

long long h[N];
long long sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];

        while (!st.empty() && h[st.top()] <= h[i]) {
            st.pop();
        }

        if (st.empty()) {
            sum[i] = 1LL * i * h[i];
        } else {
            int j = st.top();
            sum[i] = sum[j] + 1LL * (i - j) * h[i];
        }

        cout << sum[i] + 1 << " ";

        st.push(i);
    }

	return 0;
}