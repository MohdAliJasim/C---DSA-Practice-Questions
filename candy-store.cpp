#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n; std::cin >> n;
    std::vector<int> arr;
  
    while(n--){
        int num; std::cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    int budget; std::cin>> budget;

    int i = 0;
    int count = 0;
    while(budget>0){
        if(i>=arr.size()){
            break;
        }
        budget -= arr[i];
        i++;
        count++;
    }

    int ans = budget<0?count-1:count;
    std::cout << ans;
}