class Solution {
public:
    string removeOuterParentheses(string str) {
        string ans="";
        stack<char>st;
        
        if(str.empty())
            return ans;
        
        for(int i=0;i<str.length();i++){
            if(!st.empty() && st.top()=='(' && str[i]==')'){
                st.pop();
                if(!st.empty())
                    ans=ans+str[i];
            }
            else{
                st.push(str[i]);
                if(st.size()>1)
                    ans=ans+str[i];
            }            
        }
        
        return ans;
    }
};