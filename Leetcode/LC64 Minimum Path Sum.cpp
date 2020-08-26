class Solution {
public:
    int min(int a,int b){
        if(a>b)
            return b;
        else
            return a;
    }
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j){
                if(i>0 && j>0)
                    grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j];
                else{
                 if( i == 0 && j == 0);
                 else if(i == 0)
                     grid[i][j] += grid[i][j-1];
                 else if(j==0)
                     grid[i][j] += grid[i-1][j];
                }    
            }
        return grid[grid.size()-1][grid[0].size()-1];   
        
    }
};