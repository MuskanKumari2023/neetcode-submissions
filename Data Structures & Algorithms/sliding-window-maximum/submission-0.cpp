class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        multiset<int>mt;
        for(int i=0;i<k;i++)mt.insert(nums[i]);
        for(int i=k;i<n;i++){
            auto it=mt.rbegin();
            ans.push_back(*it);
            mt.erase(mt.find(nums[i-k]));
            mt.insert(nums[i]);
        }
        ans.push_back(*mt.rbegin());
        return ans;
    }
};
