//recursion
class Solution {
    bool isPalin(string &s,int start,int end){
        while(start < end){
            if(s[start] != s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    int getMinCut(string &s,int idx){
        if(idx == s.length())return -1;
        
        int ans = INT_MAX-1;
        for(int i = idx; i < s.length(); i++){
            if(isPalin(s,idx,i)){
                int temp = 1 + getMinCut(s,i+1);
                ans = min(ans,temp);
            }
        }
        return ans;
    }
public:
    int minCut(string s) {
        
        return getMinCut(s,0);
    }
};

//memo
class Solution {
    vector<int>dp;
    bool isPalin(string &s,int start,int end){
        while(start < end){
            if(s[start] != s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    int getMinCut(string &s,int idx){
        if(idx == s.length())return -1;
        
        if(dp[idx] != -1)return dp[idx];
        int ans = INT_MAX-1;
        for(int i = idx; i < s.length(); i++){
            if(isPalin(s,idx,i)){
                int temp = 1 + getMinCut(s,i+1);
                ans = min(ans,temp);
            }
        }
        return dp[idx]=ans;
    }
public:
    int minCut(string s) {
        dp.resize(s.length(),-1);
        return getMinCut(s,0);
    }
};