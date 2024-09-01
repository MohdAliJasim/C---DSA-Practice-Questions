#include<iostream>
using namespace std;

int main(){
    int n ; cin >> n;
    int cnt = 0; 
    while(n){
        if(n & 1)
            cnt++;
        n >>= 1;
    }
    int res = 0;
    for(int i =0 ;i < cnt;i++)
        res += (1 << i);
        
    cout << res;
    return 0;
}
 