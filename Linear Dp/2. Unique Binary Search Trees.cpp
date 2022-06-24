//recursion
class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1)return 1;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }
};

//memo
class Solution {
    vector<int>dp;
    int getTrees(int n){
        if(n == 0 || n == 1)return 1;
        if(dp[n] != -1)return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += getTrees(i-1)*getTrees(n-i);
        }
        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
       dp.resize(n+1,-1);
        return getTrees(n);
    }
};

//iterative
class Solution {
  
public:
    int numTrees(int n) {
       int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = 0;
           for(int j = 1;j <= i; j++){
               dp[i] += dp[j-1]*dp[i-j];
           }
        }
    return dp[n];
    }
};

//feel catlan number
//as something like pnc formation so 
//catlan no. n,n
class Solution {
public:
    long ncr(int n, int r) {
        long ans = 1;
        for(int i = 0; i < r; i++) {
            ans *= n-i;
            ans /= i+1;
        }
        return ans;   
    }
    int numTrees(int n) {
        return ncr(2*n, n) / (n + 1);
    }
};

//catlan no. further simplified n , 1
class Solution {
public:
    int numTrees(int n) {
        long ans = 1;
        for(int i = 0; i < n; i++) 
            ans *= (4*i+2) / (i+2.);
        return ans;
    }
};
