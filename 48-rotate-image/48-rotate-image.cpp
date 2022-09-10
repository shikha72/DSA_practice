class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(), t=n/2;
        int i=0;
        while(t--){
            for(int j=i;j<n-i-1;j++){
                
                int row=j, col=n-i-1;
                int temp1=matrix[i][j];
                
                while(row!=i || col!=j){
                    //swapping elements
                    int temp2=matrix[row][col];
                    matrix[row][col]=temp1;
                    temp1=temp2;
                    
                    //going to next element
                    int tmp=col;
                    col=n-row-1;
                    row=tmp;
                }
                matrix[row][col]=temp1;
            }
            i++;
        }
    }
};