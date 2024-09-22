#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void f(int arr [] , vector<int> &ds, int n , int index , int sum , int k){
  if(index == n){
    if(sum == k){
      for(auto a: ds) cout << a << " ";
      cout << endl;
    }
    return ;
  }
  ds.push_back(arr[index]);
  sum += arr[index];
  f(arr ,ds , n, index+1, sum , k);
  ds.pop_back();
  sum -= arr[index];
  
  f(arr, ds ,n ,index+1 , sum , k);
}

int main(){
  int arr[] = {1 ,2 ,1};
  vector<int> ds;
  f(arr, ds , 3 ,0 , 0,2);
}