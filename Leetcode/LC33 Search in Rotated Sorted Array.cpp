class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] == target)
            return 0;
        else if(nums.size() == 1)
            return -1;
        int count;
        if(nums[0] > target){
            count = nums.size()-1;
            while(nums[count] != target){
                if(nums[count] < target )
                    return -1;
                --count;
                if(count <0)
                    return -1;
            }
        }
        else{
            count = 1;
            while( nums[count] != target){
                if(nums[count] > target )
                    return -1;
                ++count;
                if(count >= nums.size())
                    return -1;
            }
        }
        return count;
       
    }
};