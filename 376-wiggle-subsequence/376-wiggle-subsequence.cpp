class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)
        return 1;

        if(nums.size()==2){
            if(nums[0]==nums[1])
            return 1;
            else
            return 2;
        }

        int length=0, prev_key=-1, key;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
            continue;

            if(nums[i]-nums[i-1]>0)
            key=1;
            else
            key=0;

            if(key==(!prev_key)||prev_key==-1){
                length++;
                prev_key=key;
            }
        }
        length++;
        return length;
    }
};