class Solution {
public:
    const int M = 1000000007;
    
    long long modPow (long long x, long long n){
        if(n==0)
            return 1;
        
        long long ans=1;
        while(n){
            if(n%2){
                ans=((ans%M) *x)%M;
                n=n-1;
            }
            else{
                x=((x%M)*(x%M))%M;
                n=n/2;
            }
        }
        
        return ans;
    }
     
    int countGoodNumbers(long long n) {
        
        int ans=0;
        
        if(n%2==0){
            ans= (modPow(5,n/2)%M * modPow(4,n/2)%M) %M;
        }
        else{
            ans=(modPow(5,n/2+1)%M * modPow(4,n/2)%M) %M;
        }
        
        return ans;
    }
};