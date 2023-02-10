//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
long long int dp[100001];
long long int MOD=1e9+7;

class Solution {
  public:
    long long int topDown(int n) {
        // Memoization
        if(n<=1)
        return dp[n]=n;
        
        if(dp[n]!=-1)
        return dp[n];
        
        dp[n]=(topDown(n-1)+topDown(n-2))%MOD;
        return dp[n];
    }
    long long int bottomUp(int n) {
        //Tabulation
        if(n<=1)
        return n;
        
        long long int prev2=0, prev1=1;
        for(int i=2;i<=n;i++){
            long long int curr=(prev1+prev2)%MOD;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends