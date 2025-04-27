class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        // This map stores the first index where a particular "running sum" was seen
        unordered_map<int, int> firstSeenSumIndex;
        
        int runningSum = 0;           // Tracks the running sum while looping through the array
        int maxLength = 0;            // Stores the length of the longest balanced subarray
        
        for (int i = 0; i < n; i++) {
            // Treat 0 as -1 and 1 as +1 to keep a balance between 0s and 1s
            if (nums[i] == 0) {
                runningSum += -1;
            } else {
                runningSum += 1;
            }
            
            // If runningSum is 0, the subarray from start to current index is balanced
            if (runningSum == 0) {
                maxLength = i + 1; // Update maxLength to include the entire subarray
            }
            // If runningSum was seen before, the subarray between previous index + 1 and current index is balanced
            else if (firstSeenSumIndex.find(runningSum) != firstSeenSumIndex.end()) {
                int previousIndex = firstSeenSumIndex[runningSum];
                maxLength = max(maxLength, i - previousIndex);
            }
            // If runningSum is seen for the first time, store the index
            else {
                firstSeenSumIndex[runningSum] = i;
            }
        }
        
        return maxLength;
    }
};