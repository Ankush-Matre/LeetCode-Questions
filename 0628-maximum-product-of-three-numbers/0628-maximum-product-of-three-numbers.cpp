class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    // Traverse the array
    for (int i = 0; i < n; ++i) {
        int num = nums[i];

        // Update the largest three numbers
        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }

        // Update the smallest two numbers
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    // Maximum product is either:
    // 1. Product of the three largest numbers
    // 2. Product of the two smallest numbers (negative) and the largest number
    return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};