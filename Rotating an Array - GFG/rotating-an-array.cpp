//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void leftRotate(int arr[], int n, int k) {
        // code here
        k=k%n;
	   if(n==0 || k>n)
	   return;
	   
	   int temp[k];
	   for(int j=0;j<k;j++)
	       temp[j]=arr[j];
	   
	   for(int i=0;i<n-k;i++){
	       arr[i]=arr[i+k];
	   }
	   
	   for(int i=n-k;i<n;i++){
	       arr[i]=temp[i-n+k];
	   }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends