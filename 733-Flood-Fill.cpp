class Solution {
public:
    int r , c;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    void dfs(vector<vector<int>>& image, int sr, int sc, int color , int og_color){
        if(sr < 0 or sc < 0 or sr >= r or sc >= c or image[sr][sc] != og_color) return;

        image[sr][sc] = color;

        for(int i =0 ;i < 4;i++){
            int ii = sr + dx[i];
            int jj = sc + dy[i];
            dfs(image, ii , jj , color , og_color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og_color = image[sr][sc];
        r = image.size();
        c = image[0].size();
        
        if(image[sr][sc] == color) return image;
        dfs(image, sr , sc , color, og_color);
        return image;
    }
};