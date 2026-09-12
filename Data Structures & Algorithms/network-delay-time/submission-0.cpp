class Solution {
public:
vector<vector<pair<int,int>>>g;
vector<int>vis;
vector<int>dist;
void dykstra(int src){
    dist[src]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        int curn=cur.second;
        int curd=-cur.first;
        if(vis[curn])continue;
        vis[curn]=1;
        for(auto v:g[curn]){
            if(dist[v.first]>dist[curn]+v.second){
                dist[v.first]=dist[curn]+v.second;
                pq.push({-dist[v.first],v.first});
            }
        }
    }
}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        g.resize(n+1);
        vis.assign(n+1,0);
        dist.assign(n+1,1e9);
        for(auto &x:times){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            g[u].push_back({v,w});
        }
        dykstra(k);
        int ans=-1e9;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans>=1e9)return -1;
        return ans;
    }
};
