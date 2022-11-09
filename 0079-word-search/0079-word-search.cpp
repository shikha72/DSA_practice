class Solution {
public:
    bool f(vector<vector<char>>&board, string word, int i,int j, int n,int m, int k){
        if(k>=word.size()) return true;
        if(i<0||j<0||i>=n||j>=m||board[i][j]=='.'||word[k]!=board[i][j]) 
            return false;
        if(word.size()==1 && board[i][j]==word[k]) return true;
        
        int x[4]={0,0,-1,1};
        int y[4]={-1,1,0,0};
        
        board[i][j]='.';
        bool ans=false;
        for(int idx=0;idx<4;idx++){
            ans=ans||f(board, word,i+x[idx], j+y[idx], n, m, k+1);
        }
        board[i][j]=word[k];
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        if(n==0) return false;
        if(word.size()==0) return false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(f(board, word, i, j, n, m, 0))
                        return true;
                }
            }
        }
        return false;        
    }
};