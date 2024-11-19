class Solution {
public:
int findDayWeight(vector<int>& weights, int mid){
    int days = 0;
    int cnt = 0; 
    for(int i = 0; i< weights.size();i++){
        if(cnt + weights[i] <= mid){
          cnt += weights[i];
         
        } 
        else{
            days++;
            cnt = 0;
            cnt += weights[i];
        }
         if(i == weights.size()-1) days++;  
    }

    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low  = INT_MIN;
        int high = 0;
        for(int num : weights){
            high += num;
            low = max(low, num);
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            int dayWeight = findDayWeight(weights,mid);
            if(dayWeight <= days) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};