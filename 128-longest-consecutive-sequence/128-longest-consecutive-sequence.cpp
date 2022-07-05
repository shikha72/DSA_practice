class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int len=0;
        int n=nums.size(), cnt=1;
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)
                cnt++;
            else if(nums[i]==nums[i-1])
                continue;
            else{
                len=max(len,cnt);
                cnt=1;
            }
        }
        
        len=max(len,cnt);
        return len;
    }
};