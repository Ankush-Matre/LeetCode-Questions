class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int j = 1; // pointer for odd indices

        for (int i = 0; i < nums.length; i += 2) {
            if (nums[i] % 2 != 0) {
                // find the next even number at an odd index
                while (nums[j] % 2 != 0) {
                    j += 2;
                }

                // swap nums[i] (odd at even index) with nums[j] (even at odd index)
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }

        return nums;
    }
}
