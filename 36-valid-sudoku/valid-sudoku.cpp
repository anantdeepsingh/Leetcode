class Solution {
public:
    bool Check(int row,int col,vector<vector<char>>& board){
        char ch=board[row][col];
        for(int i=0;i<9;i++){
            if(i!=col && (board[row][i]==ch)) return false;
        }
        for(int j=0;j<9;j++){
            if(j!=row && board[j][col]==ch) return false;
        }
        int nrow=row-row%3;
        int ncol=col-col%3;
        for(int i=nrow;i<nrow+3;i++){
            for(int j=ncol;j<ncol+3;j++){
                if(i==row && j==col) continue;

                if(board[i][j]==ch) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(Check(i,j,board)==false) return false;
                }
            }
        }
        return true;
    }
};