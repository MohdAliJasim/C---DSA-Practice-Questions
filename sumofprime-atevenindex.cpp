#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isPrime(int n){
  int sq = sqrt(n);
  for(int i = 2; i <= sq;i++){
    if(n%i==0)
      return false;
  }
  return true;
}

int main(){
  int n; cin >> n;
  if(n <2){
    cout << 0;
    return 0;
  }
  vector<int> arr;
  int temp = n;
  while(temp--){
    int num; cin >> num;
    arr.push_back(num);
  }
  int sum = 0;
  for(int i = 2 ;i < n;i++){
    if(isPrime(i))
      sum += arr[i];
  }
  cout << sum;
  return 0;
}