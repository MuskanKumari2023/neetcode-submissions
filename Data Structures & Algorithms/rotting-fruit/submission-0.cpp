class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>dist(n,vector<int>(m,1e9));
       queue<pair<int,int>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
                dist[i][j]=0;
            }
        }
       } 
       int dx[4]={1,0,-1,0};
       int dy[4]={0,1,0,-1};
       while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int curx=cur.first;
        int cury=cur.second;
        for(int k=0;k<4;k++){
            int nx=curx+dx[k];
            int ny=cury+dy[k];
            if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]!=0){
                if(dist[nx][ny]>dist[curx][cury]+1){
                    dist[nx][ny]=dist[curx][cury]+1;
                    q.push({nx,ny});
                }
            }
        }
       }
       int ans=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                if(dist[i][j]>=1e9)return -1;
                ans=max(ans,dist[i][j]);
            }
        }
       }
       return ans;
    }
};
