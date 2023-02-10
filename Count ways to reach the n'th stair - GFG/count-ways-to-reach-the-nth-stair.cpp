//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    long long int mod=1e9+7;
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        //It is a fibonacci series
        n=n+2;
        if(n<=1)
        return n;
        
        int prev2=1, prev1=0;
        for(int i=2;i<=n;i++){
            int curr=(prev1 +prev2)%mod;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends