class Solution {
public:
        
    int myAtoi(string str) {
        bool sign=1;
        int i=0;
        
        while(str[i]==' ' && i<str.length())
            i++;
        
        if(str[i]=='-'){
            sign=0;
            i++;
        }
        else if(str[i]=='+')
            i++;
        
        long long ans=0;
        
        for(i;i<str.length();i++){           
            if(isdigit(str[i])){               
                ans=ans*10 + (str[i]-'0');
                if(ans>=INT_MAX)
                    break;
            }
            else
                break;
        }
        
        if(sign==0)
            ans*=-1;
        
        if(ans<=INT_MIN)
            return INT_MIN;
        else if(ans>=INT_MAX)
            return INT_MAX;
        
        return ans;
    }
};