#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
//这题用到了三维动态规划 DP
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    // dp[i][j][k]：用了 i 次店、j 次花，当前酒量为 k 的方案数,我们最后要找到dp[N][M-1][1];
// 第 1 维：店的次数 i，范围 0 ~ N，所以大小 N+1
// 第 2 维：花的次数 j，因为最后一朵花单独处理，只需要到 M-1，所以大小 M
// 第 3 维：当前酒量 k，范围 0 ~ M，所以大小 M+1
    vector<vector<vector<int>>> dp(N + 1,
        vector<vector<int>>(M, vector<int>(M + 1, 0)));
    dp[0][0][2]=1;
    for(int i=0;i<=N;i++){
        for(int j=0;j<M;j++){    // 只处理前 M-1 朵花
            for(int k=0;k<=M;k++){
                if (dp[i][j][k] == 0) continue;  // 如果这个状态根本到不了，就跳过
                // 情况1：下一次遇到“店”->店次数 +1，酒量翻倍
                //1. 店的总次数不能超过 N
                //2. 翻倍后的酒量不能超过 M
                if (i + 1 <= N && k * 2 <= M) {
                    dp[i + 1][j][k * 2] =
                        (dp[i + 1][j][k * 2] + dp[i][j][k]) % MOD;
                }
                // 情况2：下一次遇到“花”->花次数 +1，酒量 -1
                // 1. 这里只统计前 M-1 朵花，所以 j+1 必须 < M
                // 2. 当前必须还有酒，即 k > 0
                if (j + 1 < M && k > 0) {
                    dp[i][j + 1][k - 1] =
                        (dp[i][j + 1][k - 1] + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    // 所以前面必须已经用了 N 次店、M-1 次花，并且还剩 1 斗酒
    // 这样最后再遇到一朵花，1 -> 0，刚好喝完
    cout << dp[N][M - 1][1] << '\n';
    return 0;
}