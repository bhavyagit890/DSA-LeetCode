class Solution {
    public:
    vector<vector<int>>direc{{1,0},{-1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int rows=grid.size(); int cols=grid[0].size();
        queue<pair<int,int>>q; int fresh=0;
for(int i=0;i<rows;i++){
    for (int j=0;j<cols;j++){
if(grid[i][j]==2){
    q.push({i,j});
}
else if (grid[i][j]==1){
    fresh++;
}
    }
}
if (fresh==0) return 0;
int mins=0;
while(!q.empty()){
    int n=q.size();
    while(n--){
        pair<int,int>curr=q.front();
        q.pop();
        int i=curr.first;
        int j=curr.second;
        for(vector<int>&dir:direc){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            
            if(new_i>=0 && new_i<rows && new_j>=0 && new_j<cols && grid[new_i][new_j]==1){
                grid[new_i][new_j]=2;
                q.push({new_i,new_j});
                fresh--;
            }
        }
    }
    mins++;
}
return fresh==0?(mins-1):-1;
    }
};