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