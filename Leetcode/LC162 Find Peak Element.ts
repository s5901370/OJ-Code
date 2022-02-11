function findPeakElement(nums: number[]): number {
    if(nums.length == 1)
        return 0;
    else if(nums.length == 2){
        if(nums[0] > nums[1])
            return 0;
        else
            return 1;
    }
    let l = 0, r = nums.length-1;
    while(l<r){
        // console.log(l);
        // console.log(r);
        let p = Math.floor((l+r)/2);
        if(p === 0 && nums[p] > nums[p+1])
            return p;
        else if(p===nums.length-1 && nums[p-1] < nums[p])
            return p;
        else if(nums[p]>nums[p+1] && nums[p]>nums[p-1]){
            return p;
        }
        else if(nums[p-1]<nums[p] && nums[p]<nums[p+1]){
            l = p+1;
        }
        else if(nums[p-1]>nums[p] && nums[p]>nums[p+1]){
            r = p-1;
        }
        else{
            l = l+1;
        }
    }
    return l;
};