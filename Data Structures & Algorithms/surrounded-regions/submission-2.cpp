class Solution {
public:
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m;
void dfs(int i,int j,vector<vector<char>>&board){
    board[i][j]='.';
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx<0 or nx>=n or ny<0 or ny>=m)continue;
        if(board[nx][ny]=='O')dfs(nx,ny,board);
    }
}
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or i==n-1 or j==0 or j==m-1){
                    if(board[i][j]=='O')dfs(i,j,board);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.')board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};
