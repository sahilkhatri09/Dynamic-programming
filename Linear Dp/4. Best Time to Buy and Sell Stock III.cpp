//recursive
class Solution {
    int getMaxProfit(vector<int>&prices,int trans,bool isHold,int idx){
        if(idx == prices.size() )return 0;
        else if(idx == prices.size())return 0;
        if(trans == 0)return 0;
        int take = 0;
        if(!isHold){
            take = -prices[idx] + getMaxProfit(prices,trans,!isHold,idx+1);
        }
        else{
            take = prices[idx] + getMaxProfit(prices,trans-1,!isHold,idx+1);
        }
        int ignore = getMaxProfit(prices,trans,isHold,idx+1);
        
        return max(take,ignore);
    }
public:
    int maxProfit(vector<int>& prices) {
        return getMaxProfit(prices,2,false,0);
    }
};

//memo
class Solution {
    int dp[2][2][100001];
    int getMaxProfit(vector<int>&prices,int trans,bool isHold,int idx){
        if(idx == prices.size() )return 0;
        else if(idx == prices.size())return 0;
        if(trans == 0)return 0;
        if(dp[trans-1][isHold][idx] != -1)return dp[trans-1][isHold][idx];
        int take = 0;
        if(!isHold){
            take = -prices[idx] + getMaxProfit(prices,trans,!isHold,idx+1);
        }
        else{
            take = prices[idx] + getMaxProfit(prices,trans-1,!isHold,idx+1);
        }
        int ignore = getMaxProfit(prices,trans,isHold,idx+1);
        
        return dp[trans-1][isHold][idx] = max(take,ignore);
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return getMaxProfit(prices,2,false,0);
    }
};

//iterative
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left [n],right[n];
        int leftMin = prices[0];
        int rightMax = prices[n-1];
        int leftAns = 0,rightAns = 0;
        for(int i = 0, j = n - 1; i < n, j >= 0; i++,j--){
            leftMin = min(leftMin,prices[i]);
            leftAns = max(leftAns,prices[i] - leftMin);
            left[i] = leftAns;
            
            rightMax = max(rightMax,prices[j]);
            rightAns = max(rightAns,rightMax-prices[j]);
            right[j] = rightAns;
        }
        
        int ans =0;
        for(int i=0; i<n; i++){
            ans = max(ans,left[i] + right[i]);
        }
        return ans;
    }
};

// n,1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = prices[0];
        int firstSell = 0;
        int secondBuy = INT_MAX;
        int secondSell = 0;
        for(int i = 0; i < prices.size(); i++){
            int curPrice = prices[i];
            firstBuy = min(firstBuy , curPrice);
            firstSell = max(firstSell , curPrice - firstBuy);
            secondBuy = min(secondBuy,curPrice - firstSell);
            secondSell = max(secondSell,curPrice - secondBuy);
        }
        return secondSell;
    }
};