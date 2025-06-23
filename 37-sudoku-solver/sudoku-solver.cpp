class Solution {
public:
    bool check(char ch,int row,int col,vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch || board[i][col]==ch) return false;
        }
        int nrow=row-row%3;
        int ncol=col-col%3;
        for(int x=nrow;x<nrow+3;x++){
            for(int y=ncol;y<ncol+3;y++){
                if(board[x][y]==ch) return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>&board){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(check(ch,i,j,board)){
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};