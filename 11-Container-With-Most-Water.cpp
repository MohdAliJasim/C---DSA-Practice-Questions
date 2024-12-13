class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;

        int l = 0; 
        int r = height.size()-1;

        while(l<r){
            int w = (r-l);
            int h = min(height[r],height[l]);
            int ans = w*h;
            maxi = max(ans, maxi);

            if(height[r] > height[l]) l++;
            else r--;
        }
        return maxi;
    }
};