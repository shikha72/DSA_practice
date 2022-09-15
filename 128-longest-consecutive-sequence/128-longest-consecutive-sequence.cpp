class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int len=0, cnt=0, i=0, n=nums.size();
        while(i<n){
            while(i+1<n && (nums[i+1]-nums[i]==1 || nums[i+1]==nums[i])){
                if(nums[i+1]-nums[i]==1)
                    cnt++;
                i++;
            }
            len=max(cnt+1, len);
            cnt=0;
            i++;
        }
        return len;        
    }
};