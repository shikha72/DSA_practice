class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        
        int start=0, end=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=temp[i]){
                start=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=temp[i]){
                end=i;
                break;
            }
        }
        
        if(start==0 && end==0)
            return 0;
        
        return end-start+1;
    }
};