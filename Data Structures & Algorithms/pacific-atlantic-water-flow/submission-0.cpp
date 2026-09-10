class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist1(n,vector<int>(m,1e9));
        vector<vector<int>>dist2(n,vector<int>(m,1e9));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0){
                    q.push({i,j});
                    dist1[i][j]=0;
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
                if(nx<0 or nx>=n or ny<0 or ny>=m)continue;
                if(dist1[nx][ny]>1+dist1[curx][cury] and heights[nx][ny]>=heights[curx][cury]){
                    dist1[nx][ny]=1+dist1[curx][cury];
                     q.push({nx,ny});
                }
            }
        }
        q=queue<pair<int,int>>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 or j==m-1){
                    dist2[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int curx=cur.first;
            int cury=cur.second;
            for(int k=0;k<4;k++){
                int nx=curx+dx[k];
                int ny=cury+dy[k];
                if(nx<0 or nx>=n or ny<0 or ny>=m)continue;
                if(dist2[nx][ny]>1+dist2[curx][cury] and heights[nx][ny]>=heights[curx][cury]){
                    dist2[nx][ny]=1+dist2[curx][cury];
                    q.push({nx,ny});
                }
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dist1[i][j]!=1e9 and dist2[i][j]!=1e9){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
