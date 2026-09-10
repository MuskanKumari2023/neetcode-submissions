class Solution {
public:
#define ll long long
int check(int mid,vector<int>&piles,int h){
    int n=piles.size();
    ll tot=0;
    for(int i=0;i<n;i++){
        tot+=((piles[i]+mid-1)/mid);
    }
    return tot<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=-1e9;
        int n=piles.size();
        for(int i=0;i<n;i++){
            // low=min(low,piles[i]);
            high=max(high,piles[i]);
        }
        int ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(check(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};
