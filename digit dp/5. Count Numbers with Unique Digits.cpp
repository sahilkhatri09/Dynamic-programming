class Solution {
    int dp[10][1<<10][2];
    int get(int idx,int mask,bool small,string &s){
        if(idx == s.length())return 1;
        if(dp[idx][mask][small] != -1)return dp[idx][mask][small];
        int limit;
        if(small)limit = 9;
        else limit = s[idx]-'0';
    
        int ans = 0;
        for(int i = 0; i <= limit; i++){
            int nsmall = (i==limit) && !small ? false : true;
            
            if(i==0 && mask == 0) ans += get(idx+1,mask,nsmall,s);
            
            else if(!(mask & 1<<i)){
                ans += get(idx + 1,1<<i | mask,nsmall,s);
            }
        }
        return dp[idx][mask][small] = ans;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        long long p = pow(10,n);
        string s = to_string(p);
        
        memset(dp,-1,sizeof dp);
       int temp = get(0,0,false,s);
        return n < 2 ? temp - 1 : temp;
    }
};