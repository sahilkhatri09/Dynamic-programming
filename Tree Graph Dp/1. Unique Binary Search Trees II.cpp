//recursion
class Solution {
    vector<TreeNode*> getTree(int start,int end){
        if(start > end)return {NULL};
        if(start==end) return {new TreeNode(start)};
        vector<TreeNode*> cur ;
         for(int i = start; i<= end; i++){

             vector<TreeNode*> left = getTree(start,i-1);
             vector<TreeNode*> right = getTree(i+1,end);
             for(int k=0;k<left.size();k++){
                 for(int j = 0;j<right.size();j++){
                    cur.push_back(new TreeNode(i,left[k],right[j]));
                 }
             }
         }
        return cur;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
       return getTree(1,n);
       
    }
};

//memo
class Solution {
    int pow[10];
   unordered_map<int,vector<TreeNode*>>dp;
    vector<TreeNode*> getTree(int start,int end){
        if(start > end)return {NULL};
        if(start==end) return {new TreeNode(start)};
        
        int power = pow[start] + pow[end];
        if(dp.find(power) != dp.end())return dp[power];
        
        vector<TreeNode*> cur ;
         for(int i = start; i<= end; i++){

             vector<TreeNode*> left = getTree(start,i-1);
             vector<TreeNode*> right = getTree(i+1,end);
             for(int k=0;k<left.size();k++){
                 for(int j = 0;j<right.size();j++){
                    cur.push_back(new TreeNode(i,left[k],right[j]));
                 }
             }
         }
        return dp[power]=cur;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        int f = 1;
        for(int i=0;i<=9;i++){
            pow[i]=f;
            f=f*2;
        }
       return getTree(1,n);
       
    }
};