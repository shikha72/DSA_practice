//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void f(int r, int c, vector<vector<int>>&vis, string s, vector<string>&ans, vector<vector<int>>m, int n){
        if(r==n-1 && c==n-1){
            ans.push_back(s);
            return;
        }
        
        int x[4]={1, 0, 0, -1};
        int y[4]={0, -1, 1, 0};
        string str="DLRU";
        
        for(int i=0;i<4;i++){
            int nx_r=r+x[i], nx_c=c+y[i];
            
            if(nx_r>=0 && nx_c>=0 && nx_r<n && nx_c<n && !vis[nx_r][nx_c] && m[nx_r][nx_c]==1){
                vis[r][c]=1;
                f(nx_r, nx_c, vis, s+str[i], ans, m, n);
                vis[r][c]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        string s="";
        
        if(m[0][0]==1)
        f(0, 0, vis, s, ans, m, n);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends