//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        vector<int>ans;
        
        //int R=a.size(), C=a[0].size();
        int a_row=0, b_row=R-1, l_col=0, r_col=C-1;
        
        while(a_row<=b_row && l_col<=r_col){
            
            for(int j=l_col;j<=r_col;j++)
                ans.push_back(a[a_row][j]);
            a_row+=1;
            
            
            
            for(int i=a_row;i<=b_row;i++)
                ans.push_back(a[i][r_col]);
            r_col-=1;
            
            
            if(b_row >= a_row){
                for(int j=r_col;j>=l_col;j--)
                    ans.push_back(a[b_row][j]);
                b_row-=1;
            }
            
            if(l_col <= r_col){
                for(int i=b_row;i>=a_row;i--)
                    ans.push_back(a[i][l_col]);
                l_col+=1;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends