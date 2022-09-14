class Solution {
public:
    //MOORE'S VOTING ALGORITHM
    int majorityElement(vector<int>& nums) {
        int cnt=0, elem=0;
        for(auto it: nums){
            if(cnt==0){
                cnt++;
                elem=it;
            }
            else if(elem!=it)
                cnt--;
            else
                cnt++;
        }
        
        return elem;
    }
};