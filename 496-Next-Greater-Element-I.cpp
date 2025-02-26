class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        unordered_map<int, pair<int,int>> map;
        for(int i = 0; i < nums1.size();i++){
            map[nums1[i]].first = 1;
            map[nums1[i]].second = i;
        }
        stack<int> st;
        for(int i = nums2.size()-1;i>=0;i--){
            if(map[nums2[i]].first){
                while(!st.empty() && st.top() < nums2[i]) st.pop();
                if(!st.empty()) {
                    res[map[nums2[i]].second] =st.top();
                }
                else res[map[nums2[i]].second] = -1;
            }                
            if(st.empty()) {
                st.push(nums2[i]);
                continue;
            }
            while(!st.empty() && st.top() < nums2[i] ){
                st.pop();
            }

            st.push(nums2[i]);
        }
        return res;
    }
};