class Solution {
public:
    int *parent;
    int find(int i){
        if(parent[i] == i)
            return i;
        else return find(parent[i]);
    }
    int findCircleNum(vector<vector<int>>& M) {
        parent = new int[M.size()];
        for(int i=0;i<M.size();i++)
            if(M[i][i] == 1)
                parent[i] = i;
        int rank[M.size()];
        memset(rank,0,sizeof(rank));
        for(int i=0;i<M.size();i++){
            for(int j=i+1;j<M.size();j++){
                if(M[i][j] == 1){
                    if(find(i) != find(j)){
                        //printf("i = %d, j = %d\n",i,j);
                        if(rank[i] > rank[j]){
                            parent[find(j)] = find(i);
                        }
                        else if(rank[i] == rank[j]){
                            rank[i]++;
                            parent[find(j)] = find(i);
                        }
                        else{
                            parent[find(i)] = find(j);
                        }
                    }  
                }
            }
        }
        int ans=0;
        for(int i=0;i<M.size();i++)
            if(parent[i] == i)
                ans++;
        return ans;
    }
};