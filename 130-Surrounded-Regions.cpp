class Solution {
public:
    int r ,c ;
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {-1,1,0,0};

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i , int j){
        if(i<0 or j < 0 or i >= r or j >= c or board[i][j] == 'X' or visited[i][j] == true ) return;

        visited[i][j] = true;

        for(int k = 0 ;k < 4; k++){
            int ii = i + dx[k];
            int jj = j + dy[k];
            dfs(board , visited, ii , jj);
        }

    }

    void solve(vector<vector<char>>& board) {
        r = board.size();
        c = board[0].size();

        vector<vector<bool>> visited(r, vector<bool>(c,false));

        for(int i =0 ;i < r ; i++){
            for(int j =0 ;j < c ;j++){
                if(i == 0 or j == 0 or i == r-1 or j == c-1){
                    if(!visited[i][j] && board[i][j] == 'O'){
                        dfs(board, visited, i ,j );
                    }
                }
            }
        }

        for(int i =0 ; i < r ; i++){
            for(int j = 0 ;j < c ; j++){
                if(!visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

    }
};