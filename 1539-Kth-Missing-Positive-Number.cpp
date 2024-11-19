class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        for(int i =0 ;i < arr.size();i++){
            map[arr[i]]++;
        }
        int cnt  =0;
        for(int i = 1; i<= INT_MAX;i++){
            if(!map[i]){
                cnt++;
                if(cnt == k) return i;
            }
        }
        return 1;
    }
};