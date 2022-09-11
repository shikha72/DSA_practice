class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort by first element
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>>ans;
        vector<int>prev=intervals[0];
        
        for(int i=1;i<intervals.size();i++){
            
            vector<int>curr=intervals[i];
            
            if(curr[0]<=prev[1]){
                int start=prev[0];
                int end=max(prev[1], curr[1]);
                
                prev.clear();
                prev.push_back(start);
                prev.push_back(end);
                
                // if(i==intervals.size()-1)
                //     ans.push_back(prev);
                // else if(intervals[i+1][0]>end){
                //     ans.push_back(prev);
                //     flag=0;
            }
            else{
                ans.push_back(prev);
                prev=curr;
            }
        }
        ans.push_back(prev);
        
        return ans;
    }
};