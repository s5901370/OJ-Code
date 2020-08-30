class Solution {
public:
    int min(int a,int b,int c){
        int ans;
        if(a>b)
            ans = b;
        else ans = a;
        if(ans >c)
            ans = c;
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int ans=0;
        int right[matrix.size()][matrix[0].size()];
        memset(right,0,sizeof(right));
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0] == '1'){
                right[i][0] = 1;
                ans = 1;
            }
        }
        for(int i=1;i<matrix[0].size();i++){
            if(matrix[0][i] == '1'){
                right[0][i] = 1 ;
                ans = 1;
            }
        }
        for(int i=1;i<matrix.size();i++)
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j] == '1')
                    right[i][j] = min(right[i-1][j-1], right[i-1][j], right[i][j-1] ) +1; // DP here 
                if(right[i][j] > ans)
                    ans = right[i][j];
            }
            
        
        
        return ans*ans;
        
    }
};