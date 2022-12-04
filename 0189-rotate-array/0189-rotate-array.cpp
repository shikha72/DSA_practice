class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        
        k=k%n;
        if(n==0 || k>n)
            return;
        
        //store n-k elements
        int arr[n-k];
        for(int i=0;i<n-k;i++)
            arr[i]=nums[i];
        
        //rotate k elements
        for(int i=0;i<k;i++)
            nums[i]=nums[i+n-k];
        
        //fill remaining elements at last
        for(int i=k;i<n;i++)
            nums[i]=arr[i-k];
        
    }
};