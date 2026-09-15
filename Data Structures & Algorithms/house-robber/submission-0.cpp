class Solution {
public:
int dp[105];
int n;
int rec(int lvl,vector<int>&nums){
    if(lvl>=n)return 0;
    if(dp[lvl]!=-1)return dp[lvl];
    int ans=rec(lvl+1,nums);
    ans=max(ans,rec(lvl+2,nums)+nums[lvl]);
    return dp[lvl]=ans;
}
    int rob(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<=n;i++)dp[i]=-1;
        return rec(0,nums);
    }
};
