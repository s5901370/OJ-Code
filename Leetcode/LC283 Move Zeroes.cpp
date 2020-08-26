class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int size = nums.size();
        while(j<size){
            while(i<size){
                if(nums.at(i) != 0){
                    ++i;
                }
                else
                    break;
            }
            if(i<size){
                j = i;
                while(j<size){
                    if(nums.at(j) == 0)
                        ++j;
                    else
                        break;
                }
                if(j< size){//change number
                    int t = nums.at(j);
                    nums[j] = nums[i];
                    nums[i] = t;
                }
                else
                    break;
            }
            else
                break;
        }
        return ;
    }
};