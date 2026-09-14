class Solution {
public:
vector<vector<pair<int,int>>>g;
vector<vector<int>>dist;
void dykstra(int src,int dst,int k){
    dist[src][0]=0;
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{src,0}});
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        int curd=-cur.first;
        int curn=cur.second.first;
        int cnt=cur.second.second;
        if(cnt>k)continue ;
        for(auto v:g[curn]){
            if(dist[v.first][cnt+1]>dist[curn][cnt]+v.second){
                dist[v.first][cnt+1]=dist[curn][cnt]+v.second;
                pq.push({-dist[v.first][cnt+1],{v.first,cnt+1}});
            }
        }
    }
}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        g.resize(n);
        dist.assign(n,vector<int>(k+2,1e9));
        for(auto &x:flights){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            g[u].push_back({v,w});
        }
        dykstra(src,dst,k);
        int ans=1e9;
        for(int i=0;i<=k+1;i++){
            ans=min(ans,dist[dst][i]);
        }
        if(ans>=1e9)return -1;
        return ans;
    }
};
