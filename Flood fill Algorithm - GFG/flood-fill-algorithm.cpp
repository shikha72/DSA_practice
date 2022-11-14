//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int m=image.size(), n=image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        queue< pair<int,int> >q;
        q.push({sr, sc});
        vis[sr][sc]=1;
        ans[sr][sc]=color;
        
        int x[]={-1, 0, 1, 0};
        int y[]={0, 1, 0, -1};
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr=r+x[i];
                int nc=c+y[i];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n && 
                   image[nr][nc]==image[sr][sc] && vis[nr][nc]==0){
                    q.push({nr, nc});
                    vis[nr][nc]=1;
                    ans[nr][nc]=color;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends