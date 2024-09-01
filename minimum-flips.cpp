#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n ; cin >> n;
    vector<int>arr;
    for(int i = 0;i < n;i++){
        int num ; cin >> num;
        arr.push_back(num);
    }
    int cnt = 0;
    bool state = true;
    for(int i = 0;i < n;i++){
        if(state && arr[i]== 0){
            cnt++;
            state = (!state);
        }
        else if(!state && arr[i] == 1){
            cnt++;
             state = (!state);
        }
    }
    cout << cnt;
    return 0;
}