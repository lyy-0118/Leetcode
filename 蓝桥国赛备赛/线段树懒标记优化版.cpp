//类型二：区间修改 + 区间查询
//加上懒标记
#include <iostream>
using namespace std;

const int N = 100005;

long long a[N];
long long tree[N * 4];
long long lazy[N * 4];

// 建树
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 下传懒标记
void pushDown(int node, int l, int r) {
    if (lazy[node] == 0) return;

    int mid = (l + r) / 2;

    int left = node * 2;
    int right = node * 2 + 1;

    // 把懒标记传给左子节点
    tree[left] += lazy[node] * (mid - l + 1);
    lazy[left] += lazy[node];

    // 把懒标记传给右子节点
    tree[right] += lazy[node] * (r - mid);
    lazy[right] += lazy[node];

    // 清空当前节点的懒标记 懒标记已经下发了，当前节点不再欠账。
    lazy[node] = 0;
}

// 区间修改：把 [ql, qr] 每个数都加上 val
void update(int node, int l, int r, int ql, int qr, long long val) {
    if (ql <= l && r <= qr) {
        tree[node] += val * (r - l + 1);
        lazy[node] += val;      //如果当前区间被完整覆盖，直接打懒标记：
        return;
    }
	//当前节点可能以前被打过懒标记
	//先下传 再递归修改左右子树
    pushDown(node, l, r);

    int mid = (l + r) / 2;

    if (ql <= mid) {
        update(node * 2, l, mid, ql, qr, val);
    }

    if (qr > mid) {
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
    }

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 区间查询：[ql, qr] 的和
long long query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[node];
    }

    pushDown(node, l, r);

    int mid = (l + r) / 2;
    long long ans = 0;

    if (ql <= mid) {
        ans += query(node * 2, l, mid, ql, qr);
    }

    if (qr > mid) {
        ans += query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (m--) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r;
            long long x;
            cin >> l >> r >> x;

            update(1, 1, n, l, r, x);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;

            cout << query(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}