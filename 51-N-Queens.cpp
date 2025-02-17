class Solution {
public:

    bool safe(vector<string>& temp, int row , int col){
        int r = row;
        int c = col;

        while(r >= 0){
            if(temp[r][c] == 'Q') return false;
            r--;
        }
        r = row;
        while(c >= 0){
            if(temp[r][c] == 'Q') return false;
            c--;
        }
        c =col;
        while(r >= 0 && c >= 0){
            if(temp[r][c] == 'Q') return false;
            c--;
            r--;
        }
        c = col;
        r  = row;
        while(r >= 0 && c < temp.size()){
            if(temp[r][c] == 'Q') return false;
            c++;
            r--;
        }
        return true;
    }


    void solve(int n , int row , vector<vector<string>>& ans, vector<string>& temp){
        if(row == n ){
            ans.push_back(temp);
            return;
        }
       

        for(int i = 0; i < n;i++){
            if(safe(temp,row,i)){
                temp[row][i] = 'Q';
                solve(n , row+1, ans , temp);
                temp[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans;
         vector<string> temp(n);
         for(int i = 0 ; i < n;i++){
            for(int j = 0 ;j < n;j++){
                temp[i].push_back('.');
            }
         }
        solve(n , 0, ans , temp);
        
         return ans;
    }
};