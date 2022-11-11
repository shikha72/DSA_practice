class Solution {
public:
    bool isValid(vector<vector<char>>board, char c, int row, int col){
        for(int i=0;i<9;i++){
            //checking for row
            if(board[row][i]==c)
                return false;
            
            //column
            if(board[i][col]==c)
                return false;
            
            //3x3 matrix
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c)
                return false;
        } 
        return true;
    }
    
    bool f(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]=='.'){
                    //if any empty cell found, 
                    //check for all char value that can be inserted
                    for(char c='1';c<='9';c++){
                        if(isValid(board, c, i, j)){
                            //enter value in board
                            board[i][j]=c;
                            
                            if(f(board))
                                return true;
                            else{
                                //backtracking
                                board[i][j]='.';
                            }
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        //if there are no empty cells in given sudoku
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};