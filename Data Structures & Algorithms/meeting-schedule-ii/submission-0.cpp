/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>>edges;
        for(auto &x:intervals){
            int s=x.start;
            int e=x.end;
            edges.push_back({s,1});
            edges.push_back({e,-1});
        }
        int maxi=0;
        int cnt=0;
        sort(edges.begin(),edges.end());
        for(auto &x:edges){
            cnt+=x.second;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
