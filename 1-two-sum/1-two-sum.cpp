class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans, store;
        store=nums;
        sort(store.begin(), store.end());
        int n=store.size();
        
        int l=0, r=n-1;
        int n1, n2;
        while(l<r){
            if(store[l]+store[r]==target){
                n1=store[l];
                n2=store[r];
                break;
            }
            else if(store[l]+store[r]>target)
                r--;
            else
                l++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1)
                ans.push_back(i);
            else if(nums[i]==n2)
                ans.push_back(i);
        }
        
        return ans;
    }
};