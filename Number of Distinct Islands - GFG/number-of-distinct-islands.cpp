//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>& grid, vector< pair<int, int> >&vec, int row0, int col0){
        int n=grid.size(), m=grid[0].size();
        vis[r][c]=1;
        vec.push_back({r-row0, c-col0});
        
        int x[]={0, -1, 0, 1};
        int y[]={-1, 0, 1, 0};
        
        for(int i=0;i<4;i++){
            int nr=r+x[i];
            int nc=c+y[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc])
            dfs(nr, nc, vis, grid, vec, row0, col0);
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        //nXm matrix
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>>st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector< pair<int, int> >vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends