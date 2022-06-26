//recursion
class Solution {
    int getMax(vector<string>&strs,int m,int n,int idx){
        if(idx == strs.size())return 0;
        int take = 0;
        int one=0,zero=0;
        for(int i=0;i<strs[idx].size();i++){
            if(strs[idx][i] == '1')one++;
            else zero++;
        }
        if(zero <= m && one <= n){
            take = 1 + getMax(strs,m-zero,n-one,idx+1);
        }
        int ignore = getMax(strs,m,n,idx+1);
        return max(take,ignore);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return getMax(strs,m,n,0);
    }
};

//memo
class Solution {
    int dp[101][101][601];
    int getMax(vector<string>&strs,int m,int n,int idx){
        if(idx == strs.size())return 0;
        if(dp[m][n][idx] != -1)return dp[m][n][idx];
        int take = 0;
        int one=0,zero=0;
        for(int i=0;i<strs[idx].size();i++){
            if(strs[idx][i] == '1')one++;
            else zero++;
        }
        if(zero <= m && one <= n){
            take = 1 + getMax(strs,m-zero,n-one,idx+1);
        }
        int ignore = getMax(strs,m,n,idx+1);
        return dp[m][n][idx] = max(take,ignore);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof dp);
        return getMax(strs,m,n,0);
    }
};