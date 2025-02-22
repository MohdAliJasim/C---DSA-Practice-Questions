class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < arr.size()){
            if(r < k-1){
                sum += arr[r];
            }
            else{
                sum += arr[r];
                if(sum/k >= threshold) ans++;
                sum -= arr[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};