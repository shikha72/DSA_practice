//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m=grid.size(), n=grid[0].size();
	    
	    vector<vector<int>> dist(m, vector<int>(n, 0));
	    vector<vector<int>> vis(m, vector<int>(n, 0));
	    queue<pair<pair<int,int>, int>>q;
	    
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){
	                vis[i][j]=1;
	                //dist[i][j]=0;
	                q.push({{i,j}, 0});
	            }
	        }
	    }
	    
	    int x[]={-1, 0, 1, 0};
	    int y[]={0, 1, 0, -1};
	    
	    while(!q.empty()){
	        int r=q.front().first.first;
	        int c=q.front().first.second;
	        int step=q.front().second;
	        q.pop();
	        
	        for(int i=0;i<4;i++){
	            int nr=r+x[i];
	            int nc=c+y[i];
	            
	            if(nr>=0 && nr<m && nc>=0 && nc<n && 
	            grid[nr][nc]==0 && !vis[nr][nc]){
	                vis[nr][nc]=1;
	                dist[nr][nc]=step+1;
	                q.push({{nr, nc}, step+1});
	            }
	        }
	    }
	    
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends