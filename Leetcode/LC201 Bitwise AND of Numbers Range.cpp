class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n)
            return m;
        int x = m;
        unsigned count = 1;
        while(x !=0){
            x/=2;
            count*=2;
        }
        if(count >= 1<<31);
        else if(count < n && count >0)n=count;
        x = m;
        //printf("count = %d, n = %d\n",count,n);
        for(unsigned i=m+1;i<=n;++i){
            
            x &= i;
        }
        return x;
    }
};