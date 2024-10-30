class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;  // If there's only one element, only one deletion is needed.

        // Finding indices of the minimum and maximum elements
        int maxIdx = 0, minIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[maxIdx]) maxIdx = i;
            if (nums[i] < nums[minIdx]) minIdx = i;
        }

        // Ensure minIdx is always smaller than maxIdx for easier calculations later
        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        // Calculate three possible strategies for deletions:
        int deleteFromFront = maxIdx + 1;             // Removing both elements from the front
        int deleteFromBack = n - minIdx;              // Removing both elements from the back
        int deleteFromBothSides = minIdx + 1 + (n - maxIdx); // Removing min from the front and max from the back

        // Return the minimum deletions among the three strategies
        return min({deleteFromFront, deleteFromBack, deleteFromBothSides});
    }
};
