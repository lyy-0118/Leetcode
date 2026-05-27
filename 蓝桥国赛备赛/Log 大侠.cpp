//规律：每个数求以2为底的对数取下整，最后都会 <= 2
//      当该数 <= 2时我们就不用再进行操作了 (剪枝)
//用线段树快速对区间进行修改和查询最大值
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10; // 数组最大长度，预留一点空间

int n, m;              // n 表示数组长度，m 表示操作次数
int a[N];              // 原数组，下标从 1 开始

// val[p] 表示线段树节点 p 所管理区间内的最大值 一般开 4 倍空间
int val[N << 2];

// 维护整个数组当前总和
long long sum = 0;

// 建树函数
// p：当前线段树节点编号
// l, r：当前节点 p 管理的区间 [l, r]
void build(int p, int l, int r) {
    // 如果当前区间只有一个元素，说明到达叶子节点
    if (l == r) {
        val[p] = a[l]; // 叶子节点的最大值就是这个位置的数组值
        return;
    }

    // 取区间中点
    int mid = (l + r) >> 1;

    // 递归建立左子树，左儿子编号为 p * 2
    build(p << 1, l, mid);

    // 递归建立右子树，右儿子编号为 p * 2 + 1
    build(p << 1 | 1, mid + 1, r);

    // 当前区间最大值 = 左右子区间最大值的较大者
    val[p] = max(val[p * 2], val[p * 2 + 1]);
}

// 区间修改函数
// p：当前线段树节点编号
// l, r：当前节点 p 管理的区间 [l, r]
// L, R：本次需要修改的目标区间 [L, R]
void modify(int p, int l, int r, int L, int R) {
    // 如果当前区间 [l, r] 和目标区间 [L, R] 没有交集，直接返回
    if (r < L || R < l) return;

    // 如果当前区间最大值 <= 2
    // 说明这个区间内所有数都 <= 2
    // 因为 1 经过操作后仍为 1，2 经过操作后仍为 2
    // 所以整个区间都不会再发生变化，可以直接跳过
    if (val[p] <= 2) return;

    // 如果到达叶子节点，说明当前只处理一个数组元素
    if (l == r) {
        int oldValue = val[p]; // 记录修改前的值

        // 将 oldValue 修改为 floor(log2(oldValue)) + 1
        int newValue = floor(log2(oldValue) + 1);
        // 因为维护的是整个数组的总和
        // 所以需要把旧值减掉，加上新值
        sum += newValue - oldValue;

        // 更新当前叶子节点的值
        val[p] = newValue;

        return;
    }

    // 当前区间不是叶子节点，继续向下递归
    int mid = (l + r) >> 1;

    // 修改左子区间
    modify(p * 2, l, mid, L, R);

    // 修改右子区间
    modify(p * 2 + 1, mid + 1, r, L, R);

    // 子节点修改完后，回溯更新当前节点的最大值
    val[p] = max(val[p * 2], val[p * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];   // 读入第 i 个元素
        sum += a[i];   // 初始化数组总和
    }
    
    // 建立线段树，根节点编号为 1，管理区间 [1, n]
    build(1, 1, n);

    // 处理 m 次操作
    while (m--) {
        int L, R;
        cin >> L >> R;  // 输入本次要修改的区间 [L, R]
        modify(1, 1, n, L, R);   // 对区间 [L, R] 执行修改操作
        cout << sum << '\n';     // 输出修改后的整个数组总和
    }

    return 0;
}