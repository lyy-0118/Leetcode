#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;
const int SIGMA = 26;
const int INF = 1e9;

int nxt[N][SIGMA];

/*
    nxt[i][c] 表示：
    从字符串第 i 个位置开始往右看，
    字符 c 第一次出现的位置。
    例如：
    s = "abac"
    nxt[2]['a'] = 3
    因为从第 2 位开始往右，a 第一次出现在第 3 位。
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    s = " " + s; // 改成 1 下标

    // 初始化 n + 1 位置，表示后面不存在任何字符
    for (int c = 0; c < SIGMA; c++) {
        nxt[n + 1][c] = INF;
    }

    // 从后往前预处理
    //nxt[i] 先复制 nxt[i + 1]，再把当前字符的位置改成 i。
    for (int i = n; i >= 1; i--) {
        // 先继承 i + 1 的信息
        for (int c = 0; c < SIGMA; c++) {
            nxt[i][c] = nxt[i + 1][c];
        }

        // 当前字符在 i 位置出现
        int c = s[i] - 'a';
        nxt[i][c] = i;
    }

	/*
        get(L, R) 的作用：
        求区间 [L, R] 去重后的字符串。
        去重规则：
        每种字符只保留第一次出现的位置。
        做法：
        对 26 个字符分别看它在 [L, R] 中第一次出现的位置。
        如果这个位置存在，就加入数组。
        最后按照出现位置排序，就能得到去重后的顺序。
    */
    // 获取区间 [L, R] 去重后的字符串
    auto get = [&](int L, int R) {
    	/*
            pair<int, char> 中：
            first  存字符第一次出现的位置
            second 存这个字符
        */
        vector<pair<int, char>> v;

        for (int c = 0; c < SIGMA; c++) { //枚举 26 个小写字母
            int pos = nxt[L][c];

            if (pos <= R) {  //如果 pos <= R，说明字符 c 在区间 [L, R] 中出现过。
                v.push_back({pos, char('a' + c)});
            }
        }

        sort(v.begin(), v.end());

        string res;
        for (auto &p : v) {
            res.push_back(p.second);
        }

        return res;
    };

	/*
        处理 m 次询问
    */
    int m;
    cin >> m;

    while (m--) {
        int La, Ra, Lb, Rb;
        cin >> La >> Ra >> Lb >> Rb;
		/*
            A 是区间 [La, Ra] 去重后的字符串
            B 是区间 [Lb, Rb] 去重后的字符串
        */
        string A = get(La, Ra);
        string B = get(Lb, Rb);

        int ans = 0;
        int len = min(A.size(), B.size());

        for (int i = 0; i < len; i++) {
            if (A[i] != B[i]) {
                ans++;
            }
        }

        ans += abs((int)A.size() - (int)B.size());

        cout << ans << '\n';
    }

    return 0;
}