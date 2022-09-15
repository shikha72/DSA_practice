class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        
        vector<int>store=nums;
        int n=store.size();
        sort(store.begin(), store.end());
        
        for(int i=0;i<n;i++){
            long long int targ=(long long)target-(long long)store[i];
            for(int j=i+1;j<n;j++){
                long long int targ2=targ-(long long int)store[j];
                int front=j+1;
                int back=n-1;
                while(front<back){
                    long long int sum=(long long)store[front]+(long long)store[back];
                    if(sum==targ2){
                        vector<int>quad(4);
                        
                        quad[0]=store[i];
                        quad[1]=store[j];
                        quad[2]=store[front];
                        quad[3]=store[back];
                        
                        ans.push_back(quad);
                        
                        while(front<back && store[front]==quad[2])
                            ++front;
                        while(front<back && store[front]==quad[3])
                            back--;
                    }
                    else if(sum<targ2)
                        front++;
                    else
                        back--;
                }
                while(j+1<n && store[j+1]==store[j])
                    ++j;
            }
            while(i+1<n && store[i+1]==store[i])
                    ++i;
        }
        
        return ans;
        
    }
};