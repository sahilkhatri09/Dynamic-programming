//Recursion
class Solution {
    int getCodes(string &s,int idx){
        if(idx == s.size())return 1;
        if(idx >= s.size())return 0;
        
        if(s[idx] == '0')return 0;
        
        int ans = 0;
        if(s[idx]=='1' && idx + 1 != s.size()){
            ans += getCodes(s,idx+2);
        }
        else if(s[idx]=='2' && idx + 1 != s.size()){
            if(s[idx + 1] >='0' && s[idx + 1] <='6'){
                ans += getCodes(s,idx+2);
            }
        }
        ans += getCodes(s,idx+1);
        return ans;
    }
public:
    int numDecodings(string s) {
       return getCodes(s,0);
    }
};

// memo
class Solution {
    vector<int>dp;
    int getCodes(string &s,int idx){
        if(idx == s.size())return 1;
        if(idx >= s.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        if(s[idx] == '0') return dp[idx] = 0;
        
        int ans = 0;
        if(s[idx]=='1' && idx + 1 != s.size()){
            ans += getCodes(s,idx+2);
        }
        else if(s[idx]=='2' && idx + 1 != s.size()){
            if(s[idx + 1] >='0' && s[idx + 1] <='6'){
                ans += getCodes(s,idx+2);
            }
        }
        ans += getCodes(s,idx+1);
        return dp[idx] = ans;
    }
public:
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
       return getCodes(s,0);
    }
};

//iterative
class Solution {
public:
    int numDecodings(string s) {
       int n = s.size();
        int dp[n+1];
        dp[0] = 1;
        
        if(s[0] == '0')dp[1] = 0;
        else dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = 0;
            if(s[i-2] == '1'){
                dp[i] += dp[i-2];
            }
            else if(s[i-2] == '2' && s[i-1]>='0' && s[i-1] <='6'){
                dp[i] += dp[i-2];
            }
            if(s[i-1] != '0')dp[i] += dp[i-1];
        }
        return dp[n];
    }
};