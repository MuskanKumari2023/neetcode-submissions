class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>q;
        int n=intervals.size();
        int m=queries.size();
        for(int i=0;i<m;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0;
        vector<int>ans(m);
        for(auto &x:q){
            int qval=x.first;
            while(i<n and intervals[i][0]<=qval){
                int s=intervals[i][0];
                int e=intervals[i][1];
                pq.push({e-s+1,e});
                i++;
            }
            while(!pq.empty() and pq.top().second<qval){
                pq.pop();
            }
            if(!pq.empty()){
                ans[x.second]=pq.top().first;
            }
            else
            {
                ans[x.second]= -1;
            }
        }
        return ans;
    }
};
