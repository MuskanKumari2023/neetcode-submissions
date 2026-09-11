class Solution {
public:
vector<vector<int>>g;
vector<int>vis;
void dfs(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v])dfs(v);
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        g.resize(n);
        vis.assign(n,0);
        for(auto &x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};
