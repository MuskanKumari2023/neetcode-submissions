class Solution {
public:
vector<vector<int>>g;
vector<int>col;
bool isCycle;
int cnt;
void dfs(int node,int par){
    cnt++;
    col[node]=1;
    for(auto v:g[node]){
        if(v==par)continue;
        if(col[v]==0)dfs(v,node);
        else if(col[v]==1){
            isCycle=true;
            break;
        }
    }
}
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        g.resize(n);
        col.resize(n,0);
        for(auto &x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        isCycle=false;
        cnt=0;
        dfs(0,-1);
        if(cnt!=n)return false;
        if(isCycle)return false;
        return true;
    }
};
