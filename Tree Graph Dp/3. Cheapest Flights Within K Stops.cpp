//recursion
class Solution {
public:
    int getMin(vector<pair<int,int>> adj[],int src,int des,int k){
        if(src == des)return 0;
        if(k < 0)return INT_MAX;
        
        int ans = INT_MAX;
        for(int i = 0;i<adj[src].size(); i++){
            int temp =  getMin(adj,adj[src][i].first,des,k-1);
            if(temp != INT_MAX) temp += adj[src][i].second;
            ans = min(ans,temp);
        }
        return ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<f.size();i++){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        int ans = getMin(adj,src,dst,k);
        return ans == INT_MAX ? -1 : ans;
    }
};

//memo
class Solution {
public:
    vector<vector<int>>dp;
    int getMin(vector<pair<int,int>> adj[],int src,int des,int k){
        if(src == des)return 0;
        if(k < 0)return INT_MAX;
        if(dp[src][k] != -1)return dp[src][k];
        int ans = INT_MAX;
        for(int i = 0;i<adj[src].size(); i++){
            int temp =  getMin(adj,adj[src][i].first,des,k-1);
            
            if(temp != INT_MAX) temp += adj[src][i].second;
            ans = min(ans,temp);
        }
        return dp[src][k]=ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        dp.resize(n,vector<int>(k+1,-1));
        for(int i=0;i<f.size();i++){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        int ans = getMin(adj,src,dst,k);
        return ans == INT_MAX ? -1 : ans;
    }
};