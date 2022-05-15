class Solution {
public:
    void dfs(int city, int n, vector <bool> &visited, vector <vector <int> > &isConnected){
        for(int neighbours = 0; neighbours < n; ++neighbours){
            if(city != neighbours and visited[neighbours] == false and isConnected[city][neighbours]){
                visited[neighbours] = true;
                dfs(neighbours, n, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = 0;
        vector <bool> visited(n);
        for(int city = 0; city < n; ++city){
            provinces += visited[city] == false ? dfs(city, n, visited, isConnected), 1 : 0;
        }
        return provinces;
    }
};
