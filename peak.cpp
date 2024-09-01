#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    int s = 0 ;
    int e = n-1;
    vector<int> arr;
    while(n--){
        int num ; cin >> num;
        arr.push_back(num);
    }
    if(arr[0] > arr[1]){
        cout << 0;
        return 0;
    }
    if(arr[e] > arr[e-1]){
        cout << e;
        return e;
    }
    int mid = s + (e-s)/2;
    while(s < e){
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            cout << mid;
            return 0;
        }
        if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]){
            s = mid+1;
        }
        else
            e = mid;
        mid = s + (e-s)/2;
    }
    cout << e;
    return 0;

}