//recursion
class Solution {
    int get(string &s, vector<string> &digits, int idx, bool small, bool start){
        if(idx == s.length())return 1;
        
        int limit;
        if(small) limit = 9;
        else limit = s[idx] - '0';
        
        int ans = 0;
        if(!start){
           ans += get(s, digits, idx + 1,true,false);
        }
        for(int i = 0; i < digits.size(); i++){
            int curVal = digits[i][0] - '0';
      
            if(curVal <= limit){
                int nsmall = (!small) && (curVal == limit) ? false : true;
                ans += get(s, digits, idx+1, nsmall, true);
            }
        }
        return ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        return get(s,digits,0,false,false) - 1;
    }
};

//memo
class Solution {
    int dp[10][2][2];
    int get(string &s, vector<string> &digits, int idx, bool small, bool start){
        if(idx == s.length())return 1;
        if(dp[idx][small][start] != -1)return dp[idx][small][start];
        
        int limit;
        if(small) limit = 9;
        else limit = s[idx] - '0';
        
        int ans = 0;
        if(!start){
           ans += get(s, digits, idx + 1,true,false);
        }
        for(int i = 0; i < digits.size(); i++){
            int curVal = digits[i][0] - '0';
      
            if(curVal <= limit){
                int nsmall = (!small) && (curVal == limit) ? false : true;
                ans += get(s, digits, idx+1, nsmall, true);
            }
        }
        return dp[idx][small][start] = ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof dp);
        return get(s,digits,0,false,false) - 1;
    }
};