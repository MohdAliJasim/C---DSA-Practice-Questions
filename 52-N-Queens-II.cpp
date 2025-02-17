class Solution {
public:


    bool safe(vector<string>& temp, int row , int col , int n){
        int r = row ;
        int c = col;

        while(c >= 0){
            if(temp[r][c] == 'Q') return false;
            c--;
        }
        c = col;
        while(r >= 0 && c >= 0){
            if(temp[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = row;
        c = col;
        while(r>=0 && c < n){
            if(temp[r--][c++] == 'Q') return false;
        }

        r = row;
        c = col;
        while(r >= 0){
            if(temp[r--][c] == 'Q') return false;
        }

        return true;
    }


    void solve(vector<string> &temp, int &count, int n , int row ){
        if(row == n){
            count++;
            return;
        }

        for(int col = 0; col < n;col++){
            if(safe(temp, row, col ,n)){
                temp[row][col] = 'Q';
                solve(temp, count , n , row+1 );
                temp[row][col] = '.';
            }
        }        
    }
    int totalNQueens(int n) {
        vector<string> temp(n);
        for(int i= 0;i < n;i++){
            for(int j=0  ;j < n;j++){
                temp[i].push_back('.');
            }
        }
        int count = 0 ;
        solve(temp, count , n , 0 );
        return count;
    }
};