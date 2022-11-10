class Solution {
public:
//     bool isSafe(int row, int col, vector<string>board, int n){
//         int r=row, c=col;
//         while(r>=0 && c>=0){
//             if(board[r][c]=='Q') return false;
//             r--;c--;
//         }
        
//         r=row, c=col;
//         while(c>=0){
//             if(board[r][c]=='Q') return false;
//             c--;
//         }
        
//         r=row, c=col;
//         while(r<n && c>=0){
//             if(board[r][c]=='Q') return false;
//             r++;c--;
//         }
        
//         return true;
//     }
    
    void f(int col, vector<string>&board, vector<vector<string>>&ans, int n, vector<int>&leftRow, vector<int>&lowDiag, vector<int>&uppDiag){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        //check for every row
        for(int i=0;i<n;i++){
            if(leftRow[i]==0 && lowDiag[i+col]==0 && uppDiag[(n-1)+(col-i)]==0){
                //placing 'Q' on board
                board[i][col]='Q';
                
                //marking 'Q' in hash maps
                leftRow[i]=1;
                lowDiag[i+col]=1;
                uppDiag[(n-1)+(col-i)]=1;
                
                f(col+1, board, ans, n, leftRow, lowDiag, uppDiag);
                
                //removing 'Q' while backtracking
                board[i][col]='.';
                
                //unmarking 'Q' in hash maps while backtracking
                leftRow[i]=0;
                lowDiag[i+col]=0;
                uppDiag[(n-1)+(col-i)]=0;
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        
        vector<int> leftRow(n, 0), lowDiag(2*n-1, 0), uppDiag(2*n-1, 0);
        
        f(0, board, ans, n, leftRow, lowDiag, uppDiag);
        
        return ans;
        
    }
};