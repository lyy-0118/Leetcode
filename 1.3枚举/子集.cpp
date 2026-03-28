#include<bits/stdc++.h>
using namespace std;
//1.位运算+状态枚举
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;   // 保存所有子集
        int n=nums.size();

        // 枚举所有状态，一共有 2^n 种
        for(int st=0;st<(1<<n);st++){
            vector<int> tmp; // 保存当前状态对应的子集
            for(int i=0;i<n;i++){
                // 判断 st 的第 i 位是否为 1
                // 如果为 1，说明 nums[i] 被选中
                if((st >> i) & 1) 
                    tmp.push_back(nums[i]);
            }
            // 当前状态对应的子集加入结果
            ret.push_back(tmp);
        }
        return ret; // 返回所有子集
    }
};

//2.回溯
class Solution2 {
vector<vector<int>> ret;
vector<int> path;
public:
 // start 表示当前从哪个下标开始选择元素
    void dfs(vector<int>& nums,int start){
        ret.push_back(path); // 当前路径就是一个子集
        for(int i=start;i<(int)nums.size();i++){
            path.push_back(nums[i]); // 选择
            dfs(nums,i+1);           // 递归
            path.pop_back();         // 回溯
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ret.clear();
        path.clear();
        dfs(nums,0);
        return ret;
    }
};

int main(){
	
}