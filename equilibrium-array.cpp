#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> arr;
  int sum = 0;
  for(int i= 0;i < n;i++){
    int num ; cin >> num;
    arr.push_back(num);
    sum += num;
  }
  int left = 0;
  int right = sum;
  
  for(int i = 0; i < n; i++){
    right -= arr[i];
    if(right == left){
      cout << i;
      return 0;
    }
    left += arr[i];
  }
  cout << -1;
  return 0;
}