class NumArray {
public:
    vector<int>array;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        array.resize(n);
        
        array[0] = nums[0];

        for(int i = 1; i < n; i++){
            array[i] = array[i - 1] + nums[i];
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return array[right];
        }
        else{
            return array[right] - array[left - 1];

        }
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */