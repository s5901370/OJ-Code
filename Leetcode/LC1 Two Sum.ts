function twoSum(nums: number[], target: number): number[] {
    let ans : number[] = [];
    let set = new Map();
    
    for (let i=0;i<nums.length;++i){
        let n = target-nums[i];
        if (set.has(n)){
            ans.push(i);
            ans.push(set.get(n));
            break;
        }
        set.set(nums[i],i);
    }
            
        
    return ans;
};