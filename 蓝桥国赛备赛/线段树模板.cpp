//线段树的结构类似于二叉树 用来对区间进行快速查询和修改
#include <iostream>            
using namespace std;             

const int N = 100005;            // 定义数组最大长度

int a[N];                        // 原数组，存放输入的数据，下标从 1 开始
long long tree[N * 4];           // 线段树数组，通常开 4 倍空间，防止越界

// 建树
void build(int node, int l, int r) {          // node 表示当前线段树节点编号，l 和 r 表示当前节点管理的区间 [l, r]
    if (l == r) {                             // 如果 l == r，说明当前区间只有一个元素，是叶子节点
        tree[node] = a[l];                    // 叶子节点的值就是原数组中对应位置的值
        return;                               // 结束递归
    }

    int mid = (l + r) / 2;                    // 计算当前区间的中点，把区间分成左右两部分

    build(node * 2, l, mid);                  // 递归建立左子树，左子节点编号是 node * 2，管理区间 [l, mid]
    build(node * 2 + 1, mid + 1, r);          // 递归建立右子树，右子节点编号是 node * 2 + 1，管理区间 [mid + 1, r]

    tree[node] = tree[node * 2] + tree[node * 2 + 1];  // 当前节点的值等于左右子节点的和
}

// 区间查询：查询 [ql, qr] 的和
long long query(int node, int l, int r, int ql, int qr) {  // node 是当前节点编号，[l,r] 是当前节点区间，[ql,qr] 是要查询的区间
    if (ql <= l && r <= qr) {                              // 如果当前区间 [l,r] 完全被查询区间 [ql,qr] 包含
        return tree[node];                                 // 直接返回当前节点保存的区间和
    }

    int mid = (l + r) / 2;                                 // 计算当前区间中点
    long long ans = 0;                                     // 用 ans 保存查询结果

    if (ql <= mid) {                                       // 如果查询区间和左子区间有交集
        ans += query(node * 2, l, mid, ql, qr);             // 递归查询左子树，并把结果加到 ans 中
    }

    if (qr > mid) {                                        // 如果查询区间和右子区间有交集
        ans += query(node * 2 + 1, mid + 1, r, ql, qr);     // 递归查询右子树，并把结果加到 ans 中
    }

    return ans;                                            // 返回最终查询到的区间和
}

// 单点修改：把位置 pos 的值改成 val
void update(int node, int l, int r, int pos, int val) {     // node 是当前节点编号，[l,r] 是当前节点区间，pos 是要修改的位置，val 是新值
    if (l == r) {                                           // 如果当前区间只有一个元素，说明找到了要修改的位置
        tree[node] = val;                                   // 把线段树中这个叶子节点的值改成 val
        return;                                             // 修改完成，返回上一层
    }

    int mid = (l + r) / 2;                                  // 计算当前区间中点

    if (pos <= mid) {                                       // 如果要修改的位置在左子区间
        update(node * 2, l, mid, pos, val);                 // 递归修改左子树
    } else {                                                // 否则说明要修改的位置在右子区间
        update(node * 2 + 1, mid + 1, r, pos, val);         // 递归修改右子树
    }

    tree[node] = tree[node * 2] + tree[node * 2 + 1];       // 子节点修改后，重新计算当前节点的区间和
}

int main() {
    int n, m;                                               // n 表示数组长度，m 表示操作次数
    cin >> n >> m;                                          // 输入 n 和 m

    for (int i = 1; i <= n; i++) {                          // 从 1 到 n 输入数组元素
        cin >> a[i];                                        // 输入第 i 个元素
    }

    build(1, 1, n);                                         // 从根节点 1 开始建树，根节点管理整个区间 [1,n]

    while (m--) {                                           // 执行 m 次操作
        int op;                                             // op 表示操作类型
        cin >> op;                                          // 输入操作类型

        if (op == 1) {                                      // 如果 op == 1，表示单点修改
            int pos, val;                                   // pos 是要修改的位置，val 是修改后的新值
            cin >> pos >> val;                              // 输入 pos 和 val
            update(1, 1, n, pos, val);                      // 从根节点开始，修改 pos 位置的值为 val
        } else if (op == 2) {                               // 如果 op == 2，表示区间查询
            int l, r;                                       // l 和 r 表示要查询的区间 [l,r]
            cin >> l >> r;                                  // 输入查询区间
            cout << query(1, 1, n, l, r) << endl;           // 从根节点开始查询 [l,r] 的区间和，并输出结果
        }
    }

    return 0;                                               
}