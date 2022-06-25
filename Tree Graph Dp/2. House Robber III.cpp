//recursion
class Solution {
    int getMax(TreeNode* root,bool flag){
        if(root == NULL)return 0;
        
        int take = 0;
        if(flag){
            take += root->val;
            take += getMax(root->left,false) + getMax(root->right,false);
        }
        int ignore = getMax(root->left,true) + getMax(root->right,true);
        
        return max(take,ignore);
    }
public:
    int rob(TreeNode* root) {
        return getMax(root,true);
    }
};

//memo


class Solution {
    map<TreeNode*,vector<int>>dp;
    int getMax(TreeNode* root,bool flag){
        if(root == NULL) return 0;
        vector<int>temp(2,-1);
        if(dp.find(root) != dp.end() && dp[root][flag] != -1)return dp[root][flag];
        int take = 0;
        if(flag){
            take += root->val;
            take += getMax(root->left,false) + getMax(root->right,false);
        }
        int ignore = getMax(root->left,true) + getMax(root->right,true);
        
        dp[root]=temp;
        return dp[root][flag] = max(take,ignore);
    }
public:
    int rob(TreeNode* root) {
        return getMax(root,true);
    }
};

//space red

class Solution {
    pair<int,int> getMax(TreeNode* root){
        if(root == NULL) return {0,0};
        pair<int,int>left = getMax(root->left);
        pair<int,int>right = getMax(root->right);
        
        int take = root->val + left.second + right.second;
        int ignore = max(left.first,left.second) + max(right.first,right.second);
        
        pair<int,int> cur;
        cur.first = take;
        cur.second = ignore;
        return cur;
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> ans = getMax(root);
        return max(ans.first,ans.second);
        
    }
};
