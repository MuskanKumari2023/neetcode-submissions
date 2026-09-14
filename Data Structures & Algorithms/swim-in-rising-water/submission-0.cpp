class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({-dist[0][0],{0,0}});
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            int curd=-cur.first;
            int curx=cur.second.first;
            int cury=cur.second.second;
            if(vis[curx][cury])continue;
            vis[curx][cury]=1;
            for(int k=0;k<4;k++){
                int nx=curx+dx[k];
                int ny=cury+dy[k];
                if(nx>=0 and nx<n and ny>=0 and ny<m){
                    if(dist[nx][ny]>max(curd,grid[nx][ny])){
                        dist[nx][ny]=max(curd,grid[nx][ny]);
                        pq.push({-dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
