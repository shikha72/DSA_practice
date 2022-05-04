class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt=0;
        map<int,int>mp;
        
        for(auto it: nums){
            mp[it]++;
        }
        
        for(auto it: nums){
            int res=k-it;
            if(mp.find(res)!=mp.end()){
                if(res==it && mp[res]<2)
                    continue;
                if(mp[res]>0 && mp[it]>0){
                    cnt++;
                    mp[it]--;
                    mp[res]--;
                }
            }
            
        }
        return cnt;
    }
};