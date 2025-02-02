class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int r = 0 , l = 0;
        while(r < nums.size()){
            
                if(nums[r] > q.front()) q.clear();
                while(!q.empty() && nums[r] > q.back()){
                    q.pop_back();
                }
                //while(!q.empty() && q.front() < nums[r]){
                  //  q.pop();
                //}/
            
         //   if()
            q.push_back(nums[r]);
            
            if(r >= k-1){
                if(!q.empty()) ans.push_back(q.front());

                if(q.front() == nums[l]) q.pop_front();

                l++;
            }
            r++;
        }
        return ans;
    }
};