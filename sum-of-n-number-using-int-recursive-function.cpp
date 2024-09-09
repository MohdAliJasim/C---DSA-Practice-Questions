#include <iostream>
#include <vector>

using namespace std;

void solve(int i , int n , vector<int> &arr){
  if(i >= n-i-1)
    return;
    
  swap(arr[i], arr[n-i-1]);
  solve(i+1, n, arr);
}

int main(){
  int n ; cin >> n;
  int temp = n; 
  vector<int> arr;
  while(temp--){
    int num ; cin >> num;
    arr.push_back(num);
  }
  solve(0 , n , arr);
  for(int i = 0 ;i < n; i++){
    cout << arr[i] << " ";
  }
}