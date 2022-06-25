//recursion
class Solution {
    bool getValid(string &s,int idx , set<string>&st){
        if(idx == s.length())return true;
        
        for(int i = idx; i < s.length() ; i++){
            string temp = s.substr(idx,i-idx+1);
            if(st.find(temp) != st.end()){
                bool temp = getValid(s,i+1,st);
                if(temp)return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string>st(wordDict.begin(),wordDict.end());
        return getValid(s,0,st);
    }
};
//memo
class Solution {
    vector<int>dp;
    bool getValid(string &s,int idx , set<string>&st){
        if(idx == s.length())return true;
        
        if(dp[idx] != -1)return dp[idx];
        for(int i = idx; i < s.length() ; i++){
            string temp = s.substr(idx,i-idx + 1);
            if(st.find(temp) != st.end()){
                bool temp = getValid(s,i+1,st);
                if(temp) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string>st(wordDict.begin(),wordDict.end());
        dp.resize(s.length(),-1);
        return getValid(s,0,st);
    }
};

//memo optimized 
class Solution {
    vector<int>dp;
    bool getValid(string &s,int idx , set<string>&st){
        if(idx == s.length())return true;
        
        if(dp[idx] != -1)return dp[idx];
        int j = s.length()-1;
        for(int i = j; i >= idx ; i--){
            string temp = s.substr(idx,i-idx+1);
            if(st.find(temp) != st.end()){
                bool temp = getValid(s,i+1,st);
                if(temp) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string>st(wordDict.begin(),wordDict.end());
        dp.resize(s.length(),-1);
        return getValid(s,0,st);
    }
};