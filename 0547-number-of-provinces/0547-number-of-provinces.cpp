class Solution {
private: // dfs application
void dfs(int node,vector<vector<int>>&adj, vector<int>&vis ){
vis[node]=1;
for(int neighbr: adj[node]){
    if(!vis[neighbr]){
        dfs(neighbr, adj,vis);
    }
}
}
public:
 int findCircleNum(vector<vector<int>>& isConnected) {
        //converting to adjacency list
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // connected components
        int provinces=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                provinces++;
                dfs(i,adj,vis);
            }
        }
        return provinces;
    }
};