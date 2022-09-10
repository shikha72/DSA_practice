class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=-1, j=nums.size(), k=0;
        while(k<j){
            if(k==i)
                k++;
            if(nums[k]==0)
                swap(nums[k], nums[++i]);
            if(nums[k]==2)
                swap(nums[k], nums[--j]);
            else
                k++;
        }
    }
};