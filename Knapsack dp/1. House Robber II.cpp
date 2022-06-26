//recursion
class Solution {
    int getMax(vector<int>&nums,int idx,int end){
        if(idx >= end)return 0;
        int take = nums[idx] + getMax(nums,idx+2,end);
        int ignore = getMax(nums,idx+1,end);
        return max(take,ignore);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int temp1 = getMax(nums,0,nums.size()-1);
        int temp2 = getMax(nums,1,nums.size());
        return max(temp1,temp2);
    }
};


//memo
class Solution {
    vector<int>dp;
    int getMax(vector<int>&nums,int idx,int end){
        if(idx >= end)return 0;
        if(dp[idx] != -1)return dp[idx];
        int take = nums[idx] + getMax(nums,idx+2,end);
        int ignore = getMax(nums,idx+1,end);
        return dp[idx]=max(take,ignore);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        dp.resize(n ,-1);
        int temp1 = getMax(nums,0,n-1);
        for(int i=0;i<n;i++)dp[i]=-1;
        int temp2 = getMax(nums,1,n);
        return max(temp1,temp2);
    }
};

//