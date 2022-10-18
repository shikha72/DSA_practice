class Solution {
public:
    
    void recur(int op, int cl, string str, int n, vector<string> &ans){
        if(op==n){
            while(cl<n){
                str+=')';
                ++cl;
            }
            ans.push_back(str);
            return;
        }
        
        if(cl>op){
            // str.pop_back();
            return;
        }
        
        // str+='(';
        recur(op+1, cl, str+"(", n, ans);
        
        //str+=')';
        recur(op, cl+1, str+")", n, ans);
    }
    
    vector<string> generateParenthesis(int n) {
      vector<string>ans;
        string str="";
        
        recur(0,0,str,n,ans);
        
        return ans;
    }
};