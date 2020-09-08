class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i=1;i<nums.size();++i){
            if(nums[i-1] == 0)
                return false;
            if(nums[i]+i >= nums.size()-1)
                return true;
            nums[i] = max(nums[i-1] -1, nums[i]);
        }
        return true;
    }
};