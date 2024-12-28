class Solution {
public:
    bool isLeap(int n){
        if(n%4==0){
            if(n%100 == 0){
                if(n%400 == 0) return true;
                return false;
            }
            return true;
        }
        return false;
    }
    int dayOfYear(string date) {
        int n = 0;
        n += date[0] -'0';
        n = n*10 + date[1] -'0';
        n = n* 10 + date[2] - '0';
        n = n*10 + date[3] -'0';

        vector<int> month = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        int m = date[5]-'0';
        m = m*10 + date[6] -'0';

        int d = date[8] - '0';
        d = d * 10 + date[9] -'0';
        int ans = 0;
        for(int i= 0 ;i < m;i++){
            ans += month[i];
        }
        ans += d;

        if(isLeap(n) && m > 2) return ans+1;
        return ans;
    }
};