function findPairs(nums: number[], k: number): number {
    let ans = 0;
    let set = new Map<number,number>();
    for (let n of nums){
        if(set.has(n))
            set.set(n,set.get(n)+1);
        else
            set.set(n,1);
    }
    for (let s of set.keys()){
        // console.log(s);
        let n1 = s,n2 = n1+k;
        if(n1===n2 && set.get(n1) > 1){
            // console.log(n1);
            ++ans;
        }
        else if(n1 !== n2 && set.has(n2)){
            
            ++ans;
        }
}
    return ans;
};