class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int onecnt = 0;
        int zerocnt = 0;
        int twocnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zerocnt++;
            }
            else if(nums[i] == 1){
                onecnt++;
            }
            else{
                twocnt++;
            }
        }
        int index = 0;
        for(int i = 0; i < zerocnt; i++){
            nums[index] = 0;
            index++;
        }

        for(int i = 0; i < onecnt; i++){
            nums[index] = 1;
            index++;
        }
        
        for(int i = 0; i < twocnt; i++){
            nums[index] = 2;
            index++;
        }
    }
};