//recursion
class Solution {
    int getMax(string &s,int idx){
       if(idx == s.size())return 0;
        int open = 0,ans = 0;
       for(int i=idx; i<s.size(); i++){
           s[i] == '(' ? open++ : open--;
           if(open < 0)break;
           if(open == 0){
               ans = i - idx + 1;
           }
       }
        ans = max(ans,getMax(s,idx + 1));
        return ans;
    }
public:
    int longestValidParentheses(string s) {
        
        return getMax(s,0);
    }
};
//iterative n,n
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int ans = 0;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty())st.push(i);
                ans = max(ans,i-st.top());
            }
        }
        return ans;
    }
};
//iterative n,1
class Solution {
  
public:
    int longestValidParentheses(string s) {
        
      int ans = 0;
        int k = 0;
        int j = -1;
        for(int i=0; i< s.size(); i++){
            if(s[i] =='('){
                k++;
            }
            else{
                k--;
                if(k==0){
                    ans = max(ans,i-j);
                }
            }
            if(k<0){
                k=0;
                j=i;
            }
        }
        
        k = 0;
        j = s.size();
        for(int i=s.size()-1; i>=0 ; i--){
            if(s[i] ==')'){
                k++;
            }
            else{
                k--;
                if(k==0){
                    ans = max(ans,j-i);
                }
            }
            if(k<0){
                k=0;
                j=i;
            }
        }
        
        return ans;
        
    }
};