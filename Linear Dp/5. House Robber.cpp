//recursion
class Solution {
    int getMaxMoney(vector<int>&nums,int idx){
        if(idx >= nums.size())return 0;
        int ans = 0;
        int take = nums[idx] + getMaxMoney(nums,idx +2);
        int ignore = getMaxMoney(nums,idx + 1);
        return max(take,ignore);
    }
public:
    int rob(vector<int>& nums) {
        return getMaxMoney(nums,0);
    }
};

//memo
class Solution {
    vector<int>dp;
    int getMaxMoney(vector<int>&nums,int idx){
        if(idx >= nums.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        int ans = 0;
        int take = nums[idx] + getMaxMoney(nums,idx +2);
        int ignore = getMaxMoney(nums,idx + 1);
        return dp[idx] = max(take,ignore);
    }
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return getMaxMoney(nums,0);
    }
};

//iterative
class Solution {
 
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
      int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2;i<=nums.size();i++){
            dp[i] = max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        return dp[n];
    }
};

// space optimization n,1
class Solution {
 
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dtake = 0;
        int take = nums[0];
        for(int i = 1;i<nums.size();i++){
            int temp = take;
            take = max(dtake + nums[i],take);
            dtake = temp;
        }
        return max(dtake,take);
    }
};