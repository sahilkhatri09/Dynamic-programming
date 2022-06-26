//recursion
class Solution {
    int getMin(vector<int>&nums1,vector<int>&nums2,int idx,int prev1,int prev2){
        if(idx == nums1.size())return 0;
        int swap = INT_MAX-1;
        if(nums2[idx] > prev1 && nums1[idx] > prev2){
            swap = 1 + getMin(nums1,nums2,idx+1,nums2[idx],nums1[idx]);
        }
        int ignore = INT_MAX-1;
        if(nums2[idx] > prev2 && nums1[idx] > prev1){
            ignore = getMin(nums1,nums2,idx+1,nums1[idx],nums2[idx]);
        }
        return min(swap,ignore);
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int temp1 = getMin(nums1,nums2,0,-1,-1);
        return temp1;
    }
};

//memo
class Solution {
    vector<vector<int>>dp;
    int getMin(vector<int>&nums1,vector<int>&nums2,int idx,bool flag){
        if(idx == nums1.size())return 0;
        if(dp[idx][flag] != -1)return dp[idx][flag];
        int prev1,prev2;
        if(flag){
            prev1 = nums2[idx-1];
            prev2 = nums1[idx-1];
        }
        else{
            prev1 = nums1[idx-1];
            prev2 = nums2[idx-1];
        }
        int swap = INT_MAX-1;
        if(nums2[idx] > prev1 && nums1[idx] > prev2){
            swap = 1 + getMin(nums1,nums2,idx+1,true);
        }
        int ignore = INT_MAX-1;
        if(nums2[idx] > prev2 && nums1[idx] > prev1){
            ignore = getMin(nums1,nums2,idx+1,false);
        }
        return dp[idx][flag]=min(swap,ignore);
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(2,-1));
        int temp1 = getMin(nums1,nums2,1,false);
        int temp2 = 1 + getMin(nums1,nums2,1,true);
        return min(temp1,temp2);
    }
};
