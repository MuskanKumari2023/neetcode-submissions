class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>ans;
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1;i<n;i++){
            int curx=intervals[i][0];
            int cury=intervals[i][1];
            if(curx<=e){
                s=min(curx,s);
                e=max(cury,e);
            }
            else{
                ans.push_back({s,e});
                s=intervals[i][0],e=intervals[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};
