//Recusive (gives TLE)
class Solution {
    int get(string &s,int idx, int count, bool small){
        if(idx == s.length()) return count;

        int limit;
        if(small) limit = 9;
        else limit = s[idx] - '0';
        
        int ans = 0;
        for(int i = 0; i <= limit; i++){
            int ncount = i == 1 ? count + 1 : count;
            int nsmall = !small && i == limit ? false : true;
            ans += get(s , idx + 1, ncount, nsmall);
        }
        return ans;
    }
public:
    int countDigitOne(int n) {
        string s = to_string(n);
     
        return get(s,0,0,false);
    }
};

//memoization (100% faster)
class Solution {
    int dp[10][10][2];
    int get(string &s,int idx, int count, bool small){
        if(idx == s.length()) return count;
        
        if(dp[idx][count][small] != -1)return dp[idx][count][small];
        int limit;
        if(small) limit = 9;
        else limit = s[idx] - '0';
        
        int ans = 0;
        for(int i = 0; i <= limit; i++){
            int ncount = i == 1 ? count + 1 : count;
            int nsmall = !small && i == limit ? false : true;
            ans += get(s , idx + 1, ncount, nsmall);
        }
        return dp[idx][count][small] = ans;
    }
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof dp);
        
        return get(s,0,0,false);
    }
};