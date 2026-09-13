class Solution {
public:
class disjointsetunion{
    private:
        vector<int>rank,parent;
    public:
        disjointsetunion(int n){
            rank.assign(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++)parent[i]=i;
        }
        int find(int x){
            if(parent[x]==x)return x;
            return parent[x]=find(parent[x]);
        }
        void merge(int x,int y){
            int rootx=find(x);
            int rooty=find(y);
            if(rootx==rooty)return ;
            if(rank[rootx]<rank[rooty])swap(rootx,rooty);
            rank[rootx]+=rank[rooty];
            parent[rooty]=rootx;
        }
};
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({d,{i,j}});
            }
        }
        sort(edges.begin(),edges.end());
        disjointsetunion dsu(n);
        int ans=0;
        for(auto &x:edges){
            int w=x.first;
            int u=x.second.first;
            int v=x.second.second;
            if(dsu.find(u)!=dsu.find(v)){
                ans+=w;
                dsu.merge(u,v);
            }
        }
        return ans;
    }
};
