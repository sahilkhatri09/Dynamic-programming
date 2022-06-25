
class Solution {
    int ans = 0;
    int getMin(TreeNode* root){
        if(root == NULL)return 1;
        int ls = getMin(root->left);
        int rs = getMin(root->right);
        
          if(ls == 0|| rs ==0){
            ans++;
            return 2;
        }
        if(ls == 2 || rs == 2)return 1;
        
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
       int val = getMin(root);
        if(val == 0)ans++;
        return ans;
    }
};