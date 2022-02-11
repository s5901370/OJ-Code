function search(nums: number[], target: number): number {
    let l = 0,r = nums.length-1;
    while(l<=r){
        let n = Math.floor((l+r)/2);
        if (nums[n] === target)
            return n;
        else if(nums[n]>target)
            r = n-1;
        else if(nums[n]<target)
            l = n+1;
            
    }
    return -1;
};