class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        if(n<1)
            return ans;
        
        ans.push_back({1});
        if(n==1)
            return ans;
        
        vector<int>prev={1,1};
        ans.push_back(prev);
        if(n==2)
            return ans;
        
        int t=n-2;
        while(t--){
            int size=prev.size()+1;
            vector<int>row(size);
            
            row[0]=1;
            for(int i=1;i<size-1;i++){
                row[i]=prev[i-1]+prev[i];
            }
            row[size-1]=1;
            
            ans.push_back(row);
            prev=row;
            row.clear();
        }
        
        return ans;
    }
};