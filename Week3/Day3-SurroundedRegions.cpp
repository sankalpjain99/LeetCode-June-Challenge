class Solution {
public:
    
    void check(vector<vector<char>>& board,int i,int j,int r,int c){
        if(board[i][j]=='O'){
            board[i][j]='1';
            if (i>1) check(board,i-1,j,r,c);
            if (j>1) check(board,i,j-1,r,c);
            if (i+1<r) check(board,i+1,j,r,c);
            if (j+1<c) check(board,i,j+1,r,c);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if(!r)
            return;
        int c = board[0].size();
        for (int i = 0; i < r; ++i) {
            check(board,i,0,r,c);             
            check(board,i,c-1,r,c);       
        }
        for (int j = 1; j < c - 1; ++j) {
            check(board,0,j,r,c);             
            check(board,r-1,j,r,c);       
        }
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};