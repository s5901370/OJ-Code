function search(nums: number[], target: number): number {
    let l = 0,r = nums.length-1;
    if(r===0 && nums[r] === target)
        return 0;
    while(nums[l]>nums[r]){ // find pivot
        let p = Math.floor((l+r)/2);
        if(nums[l] < nums[p]){
            l=p;
        }
        else{
            r = p;
        }
    }
    let pet = (r+1)%nums.length;
    l = 0,r = nums.length-1;
    while(l<=r){
       

        let p = Math.floor((l+r)/2) + pet;
        p%=nums.length;
        if(target > nums[p] ){
            l = Math.floor((l+r)/2)+1;
        }
        else if(target < nums[p]){
            r = Math.floor((l+r)/2)-1;
        }
        else{
            return p;
        }
    }
    return -1;
};