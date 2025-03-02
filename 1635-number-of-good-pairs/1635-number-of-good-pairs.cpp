class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int>mp;
        for(int i:nums){
            count = count + mp[i];
            mp[i]++;
        }
        return count;
        
    }
};