//n,1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int mini = prices[0];
        for(int i = 1;i < prices.size(); i++){
            mini = min(prices[i] , mini);
            maxProfit = max(maxProfit,prices[i] - mini);
        }
        return maxProfit;
    }
};
