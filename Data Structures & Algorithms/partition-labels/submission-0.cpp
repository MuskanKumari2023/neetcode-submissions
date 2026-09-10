class Solution {
public:
    vector<int> partitionLabels(string s) {
        if (s.empty()) return {};
        unordered_map<char,pair<int,int>>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end())mp[s[i]]={i,i};
            else mp[s[i]].second=i;
        }
        vector<pair<int,int>>v;
        for(auto &x:mp){
            v.push_back(x.second);
        }
        sort(v.begin(),v.end());
        n=v.size();
        vector<int>ans;
        int low=v[0].first;
        int high=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first<=high)high=max(high,v[i].second);
            else{
                ans.push_back(high-low+1);
                low=v[i].first;
                high=v[i].second;
            }
        }
        ans.push_back(high-low+1);
        return ans;
    }
};
