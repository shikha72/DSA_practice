class Solution {
public:
    string reverseWords(string s) {
        
        stack<string>st;
        string ans="";
        string str="";
        for(int i=0;i<=s.length();i++){
            if(s[i]==' ' || i==s.length()){
                if(!str.empty())
                st.push(str);
                str="";
            }
            else
                str=str+s[i];
        }
        
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
            
            if(!st.empty())
                ans=ans+" ";
        }
        
        return ans;
    }
};