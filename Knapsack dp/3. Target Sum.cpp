//recursion
class Solution {
    int getSum(vector<int>&nums,int target,int idx){
        if(target == 0 && idx == nums.size())return 1;
        if(idx == nums.size())return 0;
        int take = getSum(nums,target-nums[idx],idx+1);
        int ignore = getSum(nums,target+nums[idx],idx+ 1);
        return take + ignore;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return getSum(nums,target,0);
    }
};

//memo
class Solution {
    vector<vector<int>>dp;
    int Nsum;
    int getSum(vector<int>&nums,int target,int idx){
        if(target == Nsum && idx == nums.size()) return 1;
        if(idx == nums.size()) return 0;
        
        if(dp[idx][target] != -1 )return dp[idx][target];
        
        int add = getSum(nums , target - nums[idx] , idx + 1);
        int subtract = getSum(nums , target + nums[idx],idx + 1);
        
        return  dp[idx][target] = add + subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum > target && -1*sum > target)return 0;
        
        Nsum = sum;
        dp.resize(nums.size(),vector<int>(sum*3+1,-1));
        return getSum(nums,target+sum,0);
    }
};