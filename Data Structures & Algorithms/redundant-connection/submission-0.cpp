class Solution {
public:
class DisjointSetUnion{
    private:
        vector<int>rank,parent;
    public:
        DisjointSetUnion(int n)
        {
            rank.assign(n+1,1);
            parent.resize(n+1);
            for(int i=1;i<=n;i++)parent[i]=i;
        }
        int find(int x){
            if(x==parent[x])return x;
            return parent[x]=find(parent[x]);
        }
        void merge(int x, int y){
            int rootx=find(x);
            int rooty=find(y);
            if(rootx==rooty)return ;
            if(rank[rootx]<rank[rooty])swap(rootx,rooty);
            rank[rootx]+=rank[rooty];
            parent[rooty]=rootx;
        }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSetUnion dsu(n);
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            if(dsu.find(u)==dsu.find(v))return {u,v};
            dsu.merge(u,v);
        }
        return {-1,-1};
    }
};
