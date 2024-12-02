class Solution {
public:
    int search(vector<int>& arr, int target) {
        if(arr.size() ==  0) return -1;

        if(arr.size() == 1){
            if(arr[0] == target) return 0;
            else return -1;
        }
        if(arr.size() == 2){
            if(arr[0] == target) return 0;
            else if (arr[1]== target ) return 1;
            else return -1;
        }

        int ans = -1;
        int low = 0;
        int high = arr.size()-1;

        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == target) return mid;
            if(arr[low] <= arr[mid]){
                if(arr[low] <= target && target <= arr[mid]){
                    high = mid-1;
                }
                else low = mid+1;
            }
            else{
                if(arr[mid] <= target && target <= arr[high]){
                    low = mid + 1;
                }
                else high = mid-1;
            }
        }
        return -1;
    }
};