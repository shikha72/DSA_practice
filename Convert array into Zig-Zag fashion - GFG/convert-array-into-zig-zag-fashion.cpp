//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n) {
        bool ascend=1;
        for(int i=0;i<n-1;i++){
            if(ascend){
                if(arr[i]>arr[i+1])
                    swap(arr[i], arr[i+1]);
                ascend=0;
            }
            else{
                if(arr[i]<arr[i+1])
                    swap(arr[i], arr[i+1]);
                ascend=1;
            }
        }
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends