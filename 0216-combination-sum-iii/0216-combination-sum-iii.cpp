class Solution {
public:
    void f(int cnt, int idx, vector<int>ds, int sum, int target, int k, vector<vector<int>>&ans){
        if(cnt==k){
            if(sum==target)
                ans.push_back(ds);
            return;
        }
        
        for(int i=idx;i<10;i++){
            if(i>target)
                break;
            
            ds.push_back(i);
            f(cnt+1, i+1, ds, sum+i, target, k, ans);
            ds.pop_back();
            
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        f(0, 1, ds, 0, n, k, ans);
        
        return ans;
    }
};