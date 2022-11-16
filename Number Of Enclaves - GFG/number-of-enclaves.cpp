//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs (int r, int c, vector<vector<bool>>&vis, vector<vector<int>>&grid, int x[], int y[]){
        int m=grid.size(), n=grid[0].size();
        
        vis[r][c]=1;      
        
        for(int i=0;i<4;i++){
            int nr=r+x[i];
            int nc=c+y[i];
            
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr, nc, vis, grid, x, y);
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
         int m=grid.size(), n=grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, 0));
        
        int x[]={0, -1, 0, 1};
        int y[]={-1, 0, 1, 0};
        
        //traversing first and last row
        for(int j=0;j<n;j++){
            if(!vis[0][j] && grid[0][j]==1)
                dfs(0, j, vis, grid, x, y);
            
            if(!vis[m-1][j] && grid[m-1][j]==1)
                dfs(m-1, j, vis, grid, x, y);
        }
        
        //traversing first and last col
        for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i, 0, vis, grid, x, y);
            
            if(!vis[i][n-1] && grid[i][n-1]==1)
                dfs(i, n-1, vis, grid, x, y);
        }
        
        //traversing unvisited cells with value 1
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends