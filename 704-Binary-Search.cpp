class Solution {
public:
    int search(vector<int>& arr, int x) {
          int l = 0 ;
        int h= arr.size()-1;
        
        while(l <= h){
            int mid = (h+l) >> 1;
            if(arr[mid] == x) return mid;
            else if(arr[mid] > x) h = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};