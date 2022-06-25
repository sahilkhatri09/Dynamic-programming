//recursion
class Solution {
    int getDist(string &s,string &t,int i,int j){
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        
        int ans = 0;
        int take = 0;
        if(s[i] == t[j]){
            take = getDist(s,t,i+1,j+1);
        }
        int ignore = getDist(s,t,i+1,j);
        return take + ignore;
    }
public:
    int numDistinct(string s, string t) {
        return getDist(s,t,0,0);
    }
};

//memo
class Solution {
    vector<vector<int>>dp;
    int getDist(string &s,string &t,int i,int j){
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        int take = 0;
        if(s[i] == t[j]){
            take = getDist(s,t,i+1,j+1);
        }
        int ignore = getDist(s,t,i+1,j);
        return dp[i][j] = take + ignore;
    }
public:
    int numDistinct(string s, string t) {
        dp.resize(s.size(),vector<int>(t.size(),-1));
        return getDist(s,t,0,0);
    }
};

//iterative
class Solution {
public:
    int numDistinct(string s, string t) {
       int n = s.size();
        int m = t.size();
        unsigned int dp[m+1][n+1];
        for(int i=0;i<=m;i++)dp[i][0] = 0;
        for(int i=0;i<=n;i++)dp[0][i] = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(t[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
