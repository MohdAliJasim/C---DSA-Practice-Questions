class Solution {
public:


    void solve(int n , int col , vector<vector<string>>& res, vector<int>& upd, vector<int>& lowd, vector<int>& rowd,vector<string>&board){
        if(col == n){
           res.push_back(board);


            return; 
        }

        for(int row= 0; row< n;row++){
            if(upd[n-1+col-row] == 0 && lowd[col+row] == 0 && !rowd[row]){
                upd[n-1+col-row] = 1;
                lowd[col+row] = 1;
                rowd[row] = 1;
                board[row][col] = 'Q';
                solve(n ,col+1,res,upd,lowd,rowd,board);
                board[row][col] = '.';
                upd[n-1+col-row] = 0;
                lowd[col+row] = 0;
                rowd[row] = 0;
                
            }
        }
      
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n,'.');
       
        for(int i =0 ; i< n;i++){
            board[i] = s;
        }
        vector<int>upd((n*2)-1,0);
        vector<int>lowd((n*2)-1,0);
        vector<int>row(n,0);
        solve(n, 0 , res,upd,lowd,row,board);
        return res;
    }
};