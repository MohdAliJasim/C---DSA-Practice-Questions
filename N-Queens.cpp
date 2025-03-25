class Solution {
public:

    bool safe(vector<string>& temp, int row , int col){
        int nr = row;
        int nc = col;
        while(nr >= 0){
            if(temp[nr--][nc]== 'Q') return false;
        }
        nr = row;
        while(nr >= 0 && nc >= 0){
            if(temp[nr--][nc--] == 'Q') return false;
        }
        nr = row;
        nc = col;
        while(nr >= 0 && nc < temp.size()){
            if(temp[nr--][nc++] == 'Q') return false;
        }
        return true;
    }

    void solve(vector<vector<string>> & res, vector<string> & temp, int row,int n){
        if(row == n){
            res.push_back(temp);
            return ;
        }

        for(int col = 0 ;col < n;col++){
            if(safe(temp, row , col)){
                temp[row][col] = 'Q';
                solve(res, temp , row+1 , n);
                temp[row][col] = '.';
            }
        }

       
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n);
        string s = \....\;
        for(int i=0 ;i < n;i++){
            for(int j = 0;j < n;j++){
                temp[i].push_back('.');
            }
        }
        solve(res, temp, 0 ,n);
        return res;
    }
};