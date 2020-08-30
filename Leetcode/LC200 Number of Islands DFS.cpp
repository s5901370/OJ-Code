class Solution {
public:
    //version 3
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i >=0 && i < x && j>=0 && j<y && grid[i][j] == '1'){
            grid[i][j] = '2';
            dfs(grid,i+1,j);            
            dfs(grid,i-1,j);
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int num=0;
        x = grid.size();
        y = grid[0].size();
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    num++;
                }
            }
        }
        return num;
    }

    //version 2

    // struct place{
    //   int x;
    //   int y;
    // };
    // int x;
    // int y;
    // queue<place> que;
    // void dfs(vector<vector<char>>& grid,int i,int j){
    //     place a{i,j};
    //     que.push(place{i,j});
    //     while(!que.empty()){
    //         place a = que.front();
    //         que.pop();
    //         if(a.x+1 >=0  && a.x+1 < x && a.y >=0 && a.y < y && grid[a.x+1][a.y] == '1'){
    //             grid[a.x+1][a.y]='2';
    //             que.push(place{a.x+1,a.y});
    //         }
    //         if(a.x-1 >=0  && a.x-1 < x && a.y >=0 && a.y < y && grid[a.x-1][a.y] == '1'){
    //             grid[a.x-1][a.y]='2';
    //             que.push(place{a.x-1,a.y});
    //         }
    //         if(a.x >=0  && a.x < x && a.y-1 >=0 && a.y-1 < y && grid[a.x][a.y-1] == '1'){
    //             grid[a.x][a.y-1]='2';
    //             que.push(place{a.x,a.y-1});
    //         }
    //         if(a.x >=0  && a.x < x && a.y+1 >=0 && a.y+1 < y && grid[a.x][a.y+1] == '1'){
    //             grid[a.x][a.y+1]='2';
    //             que.push(place{a.x,a.y+1});
    //         }
    //     }
    // }
    // int numIslands(vector<vector<char>>& grid) {
    //     if(grid.size() == 0)
    //         return 0;
    //     int num=0;
    //     x = grid.size();
    //     y = grid[0].size();
    //     for(int i=0;i<x;i++){
    //         for(int j=0;j<y;j++){
    //             if(grid[i][j] == '1'){
    //                 dfs(grid,i,j);
    //                 num++;
    //             }
    //         }
    //     }
    //     return num;
    // }
    

    //version 1
//     bool **visited;
//     queue<place> que;
//     void dfs(vector<vector<char>>& grid,int i,int j){
//         place a{i,j};
//         que.push(place{i,j});
//         while(!que.empty()){
//             place a = que.front();
//             que.pop();
//             if(a.x+1 >=0  && a.x+1 < x && a.y >=0 && a.y < y && grid[a.x+1][a.y] == '1' && visited[a.x+1][a.y] == false){
//                 visited[a.x+1][a.y]=true;
//                 que.push(place{a.x+1,a.y});
//             }
//             if(a.x-1 >=0  && a.x-1 < x && a.y >=0 && a.y < y && grid[a.x-1][a.y] == '1' && visited[a.x-1][a.y] == false){
//                 visited[a.x-1][a.y]=true;
//                 que.push(place{a.x-1,a.y});
//             }
//             if(a.x >=0  && a.x < x && a.y-1 >=0 && a.y-1 < y && grid[a.x][a.y-1] == '1' && visited[a.x][a.y-1] == false){
//                 visited[a.x][a.y-1]=true;
//                 que.push(place{a.x,a.y-1});
//             }
//             if(a.x >=0  && a.x < x && a.y+1 >=0 && a.y+1 < y && grid[a.x][a.y+1] == '1' && visited[a.x][a.y+1] == false){
//                 visited[a.x][a.y+1]=true;
//                 que.push(place{a.x,a.y+1});
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         if(grid.size() == 0)
//             return 0;
//         int num=0;
//         x = grid.size();
//         y = grid[0].size();
            
//         visited = new bool*[x];
//         for(int a=0;a<x;a++)
//             visited[a] = new bool[y];
//         for(int i=0;i<x;i++)
//             for(int j=0;j<y;j++)
//                 visited[i][j]=false;
//         int ans=0;
//         for(int i=0;i<x;i++){
//             for(int j=0;j<y;j++){
//                 if(!visited[i][j]){
//                     if(grid[i][j] == '1'){
//                         dfs(grid,i,j);
//                         num++;
//                     }
//                     else
//                         visited[i][j] = true;
//                 }
//             }
//         }
//         return num;
//     }
};