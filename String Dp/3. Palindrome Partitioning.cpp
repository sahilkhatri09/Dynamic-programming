//recursion
class Solution {
    vector<vector<string>>allPartition;
    vector<string>temp;
    bool check(string&s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end])return false;
            start++;end--;
        }
        return true;
    }
public:
    void helper(string &s,int idx){
        if(idx==s.size()){allPartition.push_back(temp);return;}
        for(int i=idx;i<s.size();i++){
            if(check(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                helper(s,i+1);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        helper(s,0);
        return allPartition;
    }
};

