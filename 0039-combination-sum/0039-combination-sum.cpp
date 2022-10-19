class Solution {
public:
    void solve(int idx, vector<int>&ds, vector<int>arr, vector<vector<int>>&ans, int target){
        if(idx==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;   
        }
        
        //pick
        if(arr[idx]<=target){
            ds.push_back(arr[idx]);
            solve(idx, ds, arr, ans, target-arr[idx]);  
            ds.pop_back();
            //necessary to pop_back while backtracking because ds is taken in reference
        }
        
        //not pick
        
        solve(idx+1, ds, arr, ans, target);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        solve(0, ds, candidates, ans, target);
        
        return ans;
    }
};