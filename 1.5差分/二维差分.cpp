#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> diff, a;

// 二维差分给子矩形 (x1, y1) 到 (x2, y2) 中的每个元素加上 v
void add(int x1, int y1, int x2, int y2, int v) {
    diff[x1][y1] += v;
    diff[x2 + 1][y1] -= v;
    diff[x1][y2 + 1] -= v;
    diff[x2 + 1][y2 + 1] += v;
}

// 执行完所有 add 操作后，调用这个函数恢复最终矩阵
void prefix_sum() {
    // 先复制差分数组
    a = diff;
    // 第一步：按列做前缀和（从上往下累加）
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] += a[i - 1][j];
        }
    }
    // 第二步：按行做前缀和（从左往右累加）
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] += a[i][j - 1];
        }
    }
}

void prefix_sum2(){	
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] =a[i-1][j]+a[i][j-1]-a[i-1][j-1]+diff[i][j];
        }
    }

}

int main() {
    cin >> n >> m;
    // 开 n+2 和 m+2，防止访问边界时越界
    diff.assign(n + 2, vector<int>(m + 2, 0));
    a.assign(n + 2, vector<int>(m + 2, 0));
    // 示例：给矩形 (1,1) ~ (2,2) 每个元素加 5
    add(1, 1, 2, 2, 5);
    // 再给矩形 (2,2) ~ (3,3) 每个元素加 3
    add(2, 2, 3, 3, 3);
    // 通过二维前缀和恢复最终矩阵
    prefix_sum2();

    // 输出结果矩阵
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}