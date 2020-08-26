class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN,cur = INT_MIN;
        
        int i=0,j=0;
        while(j < nums.size()){
            if(cur < nums.at(j) && cur < 0){//change to a new subarray
                i = j;
                cur = nums.at(i);
                ++j;
                if(cur > max)
                    max = cur;
            }
            else{// just j++
                cur += nums.at(j);
                if(cur > max)
                    max = cur;
                ++j;
            }
            printf("cur=%d max=%d\n",cur,max);
        }
        return max;
    }
};