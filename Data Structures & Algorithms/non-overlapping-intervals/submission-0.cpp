class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)  {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int ans=0;
        int prevEnd=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prevEnd){
                prevEnd=min(prevEnd,intervals[i][1]);
                ans++;
            }
            else prevEnd=intervals[i][1];
        }
        return ans;
    }
};
