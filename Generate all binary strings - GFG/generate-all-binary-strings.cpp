//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void recursion (int idx, string s, bool prev, int n){
        if(idx==n){
            //print str
            cout<<s<<" ";
            return;
        }
        
        //NOT PICK
        recursion(idx+1, s+'0', 0, n);
        
        //PICK if prev!=1
        if(prev!=1)
        recursion(idx+1, s+'1', 1, n);
        
    }
    
    void generateBinaryStrings(int num){
        //Write your code
        string str="";
        recursion(0, str, 0, num);
        
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends