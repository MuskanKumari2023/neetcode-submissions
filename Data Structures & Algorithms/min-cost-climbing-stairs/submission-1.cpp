class Solution {
public:
int dp[105];
int n;

int rec(int lvl,vector<int>&cost){
    if(lvl>=n)return 0;
    // if(lvl==n)return 0;
    if(dp[lvl]!=-1)return dp[lvl];
    int ans=min(rec(lvl+1,cost),rec(lvl+2,cost))+cost[lvl];
    return dp[lvl]=ans;
}
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        for(int i=0;i<n;i++)dp[i]=-1;
        return min(rec(0,cost),rec(1,cost));
    }
};
