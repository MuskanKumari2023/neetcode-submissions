class Solution {
public:
vector<vector<int>>vis;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool check(int x,int y,int n,int m){
    return (x>=0 and x<n and y>=0 and y<m);
}
void dfs(int i,int j,vector<vector<char>>&grid){
    vis[i][j]=1;
    int n=grid.size();
    int m=grid[0].size();
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(check(nx,ny,n,m)){
            if(!vis[nx][ny] and grid[nx][ny]=='1'){
                dfs(nx,ny,grid);
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vis.assign(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
