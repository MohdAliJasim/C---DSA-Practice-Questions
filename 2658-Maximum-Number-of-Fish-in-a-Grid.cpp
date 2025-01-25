class Solution {
public:
    int r, c;
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {-1,1,0,0};

    int floodfill(vector<vector<int>> & grid , int x , int y){
        if(x<0 or y<0 or x>=r or y>=c or grid[x][y] == 0) return 0;
        int res = grid[x][y];
        grid[x][y]=0;
        int ans = 0;
        for(int k = 0 ; k < 4;k++){
            int i = x + dx[k];
            int j = y + dy[k];
            ans += floodfill(grid , i , j);
        }
        return ans + res;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        int maxi = 0 ;
        for(int i= 0;i < r ;i++){
            for(int j =0 ;j < c ;j++){
                if(grid[i][j] != 0){
                    int ans = floodfill(grid, i , j);
                    maxi = max(maxi, ans);
                }
            }
        }
        return maxi;
    }
};