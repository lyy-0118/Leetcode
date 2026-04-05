class Solution {
public:
    int dfs(TreeNode* crt){
        if(!crt) return 0;
        else{
            int leftnum=dfs(crt->left);
            int rightnum=dfs(crt->right);
            return max(leftnum,rightnum)+1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(dfs(root->left)-dfs(root->right))<=1){
            return isBalanced(root->left)&&isBalanced(root->right);
        }else return false;
    }
};