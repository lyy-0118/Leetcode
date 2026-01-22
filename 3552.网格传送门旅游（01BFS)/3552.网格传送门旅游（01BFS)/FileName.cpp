#include <vector>
#include <string>
#include <deque>
#include <tuple>
#include <climits> // for INT_MAX
using namespace std;
//https://leetcode.cn/problems/grid-teleportation-traversal/

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        //1.初始化
        int m = matrix.size(), n = matrix[0].size(); //初始化行和列
        vector<pair<int, int>> group[26]; //记录字母A-Z出现的位置
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isupper(matrix[i][j])) { //isupper检查是否为大写字母
                    group[matrix[i][j] - 'A'].push_back({ i,j }); //将坐标i,j存储进group
                }
            }
        }
        //存储到达i,j的最小距离,初始化为无穷大
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq; //双端队列dq,存储坐标
        vector<bool> IsUsed(26, false); //记录A-Z传送门是否被用过
        dist[0][0] = 0;
        dq.push_front({ 0,0 });
        int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
        //2.最短路径逻辑
        while (!dq.empty()) {
            auto [r,c] = dq.front();//当前坐标
            dq.pop_front();
            int current_cs = dist[r][c];
            //到达终点
            if (r == m - 1 && c == n - 1) return current_cs;
            char crt = matrix[r][c];  //当前坐标字母

            //A：选择传送门(是字母且未被使用)
            if (isupper(crt) && !IsUsed[crt - 'A']) {
                IsUsed[crt - 'A'] = true;
                for (auto& next_pos : group[crt - 'A']) {
                    int nr = next_pos.first, nc = next_pos.second;
                    if (dist[nr][nc] > current_cs) {
                        dist[nr][nc] = current_cs;
                        dq.push_front({ nr,nc });
                    }
                }
            }
            //B：普通移动
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                //检查边界及是否可移动
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] != '#' && dist[nr][nc] > current_cs + 1) {
                    dist[nr][nc] = current_cs + 1; // 移动增加1步
                    dq.push_back({ nr, nc });          // 权重为1，加到队尾
                }
            }
        }
        return -1;

    }
};

int main() {

}