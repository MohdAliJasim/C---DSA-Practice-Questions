class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        while(num){
            int dig = num%10;
            nums.push_back(dig);
            num = num/10;
        }
        reverse(nums.begin(),nums.end());

        for(int i = 0; i < nums.size();i++){
            int index = -1;
            int temp = nums[i];
            for(int j = i+1; j < nums.size();j++){
                if(temp <= nums[j] && nums[j] != nums[i]){
                    index = j;
                    temp = nums[j];
                }
            }
            if(index != -1){
                swap(nums[i], nums[index]);
                break;
            }
        }
        for(int i= 0;i < nums.size();i++){
            num= num*10 + nums[i];
        }
        return num;
    }
};