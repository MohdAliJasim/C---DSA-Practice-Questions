class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int size = arr.size();
        int count[size];
        int countElement;
        int index=-1;
        
        if(size == 2){
            return false;
        }
        if(size == 1){
            return true;
        }
        
        sort(arr.begin(),arr.end());
        int i = 0;
        while(i < size){
            countElement = 1;
                 while(i<size-1   &&  arr[i] == arr[i+1]){
                countElement++;
                 i++;   
                }
            index++;
            count[index]= countElement;
            i++;
            }
        
        for(int i = 0; i<index;i++){
            for (int j = i+1; j<= index; j++){
                if(count[i]==count[j]){
                    return false;
                }
            }
        }
        return true;
    }
};