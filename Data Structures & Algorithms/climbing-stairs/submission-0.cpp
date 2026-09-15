class Solution {
public:
int dp[46];
int rec(int n){
    if(n<0)return 0;
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    int ans=0;
    ans+=rec(n-1)+rec(n-2);
    return dp[n]=ans;
}
    int climbStairs(int n) {
        for(int i=0;i<=n;i++)dp[i]=-1;
        return rec(n);
    }
};
