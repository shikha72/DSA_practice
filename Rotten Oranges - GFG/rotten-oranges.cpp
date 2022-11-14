//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int vis[m][n];
        
        queue< pair< pair<int,int>, int> >q;//{{row, col}, time}
        int time=0, cnt=0, cntfresh=0;
        
        //traverse all rotten oranges
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    //count all oranges that were fresh in the beginning
                    cntfresh++;
                    vis[i][j]=0;
                }
                else 
                    vis[i][j]=0;
                
            }
        }
        
        //to traverse all 4-directionally neighbour
        int x[]={-1, 0, 1, 0};
        int y[]={0, 1, 0, -1};
        
        //BFS traversal
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            
            time=max(time, t);
            
            for(int i=0;i<4;i++){
                int row=r+x[i];
                int col=c+y[i];
                
                if(row>=0 && row<m && col>=0 && col<n && 
                   vis[row][col]!=2 && grid[row][col]==1){
                    
                    q.push({{row, col}, t+1});
                    vis[row][col]=2;
                    
                    //keeping track of all oranges being rotten
                    cnt++;
                }
            }
        }
        
        if(cnt!=cntfresh)
            return -1;
        
        return time; 
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends