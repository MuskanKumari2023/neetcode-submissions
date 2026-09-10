class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        set<vector<int>>temp;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    temp.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum>0)k--;
                else j++;
            }
        }
        for(auto &s:temp)ans.push_back(s);
        return ans;
    }
};
