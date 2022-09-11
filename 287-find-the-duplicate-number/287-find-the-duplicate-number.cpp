class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            if(temp<0)
                    temp=nums[i]-(2*nums[i]);
            
            if(nums[temp-1]<0)
                return temp;
            else               
                nums[temp-1]=0-nums[temp-1];
        }
        return -1;
    }
};