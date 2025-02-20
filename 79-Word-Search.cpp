class Solution {
public:
    int n , m;
    vector<int>dx = {0,0,-1,1};
    vector<int>dy = {-1,1,0,0};

    bool solve(vector<vector<char>>& board, string &word, int index , vector<vector<bool>>& vis, int x, int y){
        if(index == word.size()) return true;
        if(x < 0 or y < 0 or  x >= n or y >= m or board[x][y] != word[index] or vis[x][y] == true) return false;

        vis[x][y] = true;

        for(int i=0;i < 4;i++){
            int ii = x + dx[i];
            int jj = y + dy[i];

            if(solve(board , word ,index+1, vis, ii, jj)) return true;
        }
        vis[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();


        for(int i = 0 ;i < n;i++){
            for(int j = 0 ;j < m;j++){
                vector<vector<bool>> vis(n , vector<bool>(m, false));
                if(board[i][j] == word[0]){
                    if(solve(board,word,0,vis,i,j)) return true;
                }
            }
        }
        return false;
    }
};