class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int arr1[nums.size()];
        int arr2[nums.size()];
        vector<int> ans;
        arr1[0] = 1;
        arr2[nums.size()-1] = 1;
        for(int i=1;i<nums.size();++i){
            arr1[i] = arr1[i-1] * nums[i-1];
            arr2[nums.size()-i-1] = nums[nums.size()-i]*arr2[nums.size()-i];
        }
        
        for(int i=0;i<nums.size();++i){
            ans.push_back(arr2[i]*arr1[i]);
        }
        return ans;
    }
};