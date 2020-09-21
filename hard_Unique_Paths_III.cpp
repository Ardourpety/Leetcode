class Solution {
public:
    
    int dfs(vector<vector<int>>& g,int i,int j,int s,int t_s){
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j]==-1)return 0;
        
        if(g[i][j]==2) return s==t_s?1:0;
        
        g[i][j]=-1;
        int path=dfs(g,i+1,j,s+1,t_s)+dfs(g,i,j+1,s+1,t_s)+dfs(g,i-1,j,s+1,t_s)+dfs(g,i,j-1,s+1,t_s);
        g[i][j]=0;
        return path;
    }
    
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ii=0,jj=0,step=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){ii=i;jj=j;}
                if(grid[i][j]!=-1){step++;}
            }
        }
        
        return dfs(grid,ii,jj,1,step);
    }
};
