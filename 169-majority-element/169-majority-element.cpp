class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        int n=nums.size();
        n=n/2;
        
        for(auto it:nums){
            mp[it]++;
        }
        
        for(auto it:mp){
            if(it.second>n)
                return it.first;
        }
        
        return 0;
    }
};