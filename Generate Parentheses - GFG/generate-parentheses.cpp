//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void recursion(int idx, int open, string s, int n, vector<string>&ans){
        if(idx==n){
            while(open--){
                s=s+')';
            }
            ans.push_back(s);
            return;
        }
        
        //NOT PICK- CLOSE
        if(open>0)
        recursion(idx, open-1, s+')', n, ans);
        
        //PICK - OPEN
        recursion(idx+1, open+1, s+'(', n, ans);
        
    }
    
    vector<string> AllParenthesis(int n) 
    {
        string str="";
        vector<string>ans;
        
        recursion(0, 0, str, n, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends