class Solution {
public:
    void solve (int idx, vector<vector<int>>&ans, vector<int>nums, vector<int>&ds){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[idx]);
        solve(idx+1, ans, nums, ds);
        
        ds.pop_back();
        solve(idx+1, ans, nums, ds);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int i=0;
        
        solve(i, ans, nums, ds);
        
        return ans;
    }
};