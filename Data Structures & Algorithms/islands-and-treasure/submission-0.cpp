class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long>>dist(n,vector<long>(m,1e12));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int dx[4]={1,0,0,-1};
        int dy[4]={0,1,-1,0};
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=cur.first+dx[k];
                int ny=cur.second+dy[k];
                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]!=-1){
                    if(dist[nx][ny]>dist[cur.first][cur.second]+1){
                        dist[nx][ny]=dist[cur.first][cur.second]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2147483647){
                    if(dist[i][j]>=1e12)continue;
                    grid[i][j]=dist[i][j];
                }
            }
        }
    }
};
