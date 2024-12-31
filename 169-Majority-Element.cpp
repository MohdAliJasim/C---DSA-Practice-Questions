class Solution {
public:
    int majorityElement(vector<int>& arr) {
         int ele;
        int cnt = 0;
        for(int i= 0;i < arr.size();i++){
            if(cnt == 0){
                ele = arr[i];
                cnt=1;
            }
            else if(ele == arr[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        cnt =0;
        for(int i =0 ;i < arr.size();i++){
            if(arr[i] == ele){
                cnt++;
            }
        }
        int n = arr.size();
        return cnt > n/2?ele:-1;
    }
};