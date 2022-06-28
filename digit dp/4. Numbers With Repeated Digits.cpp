//recursion
class Solution {
    int get(string &s,int idx,int mask, bool small,bool repeated){
        if(idx == s.length())return repeated;
        
        int limit;
        if(small)limit = 9;
        else limit = s[idx] - '0';
        
        int ans = 0;
        for(int i = 0; i <= limit; i++){
            int nsmall = (i == limit) && !small ? false : true;
            
            if(i==0 & mask ==0) ans += get(s,idx+1,mask,nsmall,false);
            else if(mask & 1<<i) ans += get(s,idx + 1,mask,nsmall,true);
            else{
                int nmask = mask|1<<i;
                ans += get(s,idx+1,nmask,nsmall,repeated);
            }
        }
        return ans;
    }
    
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        return get(s,0,0,false,false);
    }
};

//memoization
class Solution {
    int dp[10][1<<10][2][2];
    int get(string &s,int idx,int mask, bool small,bool repeated){
        if(idx == s.length())return repeated;
        if(dp[idx][mask][small][repeated] != -1)return dp[idx][mask][small][repeated];
        int limit;
        if(small)limit = 9;
        else limit = s[idx] - '0';
        
        int ans = 0;
        for(int i = 0; i <= limit; i++){
            int nsmall = (i == limit) && !small ? false : true;
            
            if(i==0 & mask ==0) ans += get(s,idx+1,mask,nsmall,false);
            else if(mask & 1<<i) ans += get(s,idx + 1,mask,nsmall,true);
            else{
                int nmask = mask|1<<i;
                ans += get(s,idx+1,nmask,nsmall,repeated);
            }
        }
        return dp[idx][mask][small][repeated] = ans;
    }
    
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof dp);
        return get(s,0,0,false,false);
    }
};