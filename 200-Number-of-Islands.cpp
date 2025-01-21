class Solution {
public:
    int r ,c;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    void dfs(vector<vector<char>>& grid, int i ,int j){
        if(i < 0 or j < 0 or  j >= c or i >= r or grid[i][j] != '1') return;

        grid[i][j] = '2';

        for(int k = 0; k < 4;k++){
            int ii = i + dx[k];
            int jj = j + dy[k];
            dfs(grid, ii, jj);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int count = 0;
        for(int i = 0;i < r;i++){
            for(int j = 0 ;j < c;j++){
                if(grid[i][j] == '1'){
                    dfs(grid , i, j);
                    count++;
                }
            }
        }
        return count;
    }
};