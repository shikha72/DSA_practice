class Solution {
public:
    void f(int idx, int tar, vector<int>ds, vector<vector<int>>&ans, vector<int>arr){
        if(tar==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx; i<arr.size();i++){
            if(arr[i]>tar)
                break;
            
            //to include unique combinations only
            if(i>idx && arr[i]==arr[i-1])
                continue;
            
            ds.push_back(arr[i]);
            f(i+1, tar-arr[i], ds, ans, arr);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        
        f(0, target, ds, ans, candidates);
        
        return ans;
    }
};