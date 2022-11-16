class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>&vis, vector<vector<char>> &board, int x[], int y[]){
        vis[r][c]=1;
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<4;i++){
            int nr=r+x[i];
            int nc=c+y[i];
            
            //traversing all O nodes connected to boundary somehow
            if(nr>=0 && nr<m && nc>=0 && nc<n && 
               !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr, nc, vis, board, x, y);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, 0));
        
         int y[]={-1, 0, 1, 0};
        int x[]={0, -1, 0, 1};
        
        //traverse first row and last row
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0, j, vis, board, x, y);
            }
            
            if(board[m-1][j]=='O' && !vis[m-1][j]){
                dfs(m-1, j, vis, board, x, y);
            }
        }
        
        //traverse first and last col
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !vis[i][0])
                dfs(i, 0, vis, board, x, y);
            
            if(board[i][n-1]=='O' && !vis[i][n-1])
                dfs(i, n-1, vis, board, x, y);
        }
        
        //traversing all cells and flipping
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                    vis[i][j]=1;
                }
            }
        }
    }
};