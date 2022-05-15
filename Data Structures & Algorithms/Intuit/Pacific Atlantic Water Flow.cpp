class Solution {
private:
    vector <int> dx {-1, 1, 0, 0}, dy {0, 0, 1, -1};

public:
    bool isValid(int row, int col, int n, int m){
        return row >= 0 and col >= 0 and row < n and col < m;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector <vector <bool> > reachPacific(n, vector <bool> (m));
        queue <pair <int, int> > q;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == 0 or j == 0){
                    q.push({i, j});
                    reachPacific[i][j] = true;
                }
            }
        }   
        while(q.empty() == false){
            pair <int, int> currentCell = q.front();
            q.pop();
            for(int d = 0; d < 4; ++d){
                int newRow = currentCell.first + dx[d], newCol = currentCell.second + dy[d];
                if(isValid(newRow, newCol, n, m) and !reachPacific[newRow][newCol] and heights[newRow][newCol] >= heights[currentCell.first][currentCell.second]){
                    q.push({newRow, newCol});
                    reachPacific[newRow][newCol] = true;
                }
            }
        }
        
        vector <vector <bool> > reachAtlantic(n, vector <bool> (m));
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == n - 1 or j == m - 1){
                    q.push({i, j});
                    reachAtlantic[i][j] = true;
                }
            }
        }

        while(q.empty() == false){
            pair <int, int> currentCell = q.front();
            q.pop();
            for(int d = 0; d < 4; ++d){
                int newRow = currentCell.first + dx[d], newCol = currentCell.second + dy[d];
                if(isValid(newRow, newCol, n, m) and !reachAtlantic[newRow][newCol] and heights[newRow][newCol] >= heights[currentCell.first][currentCell.second]){
                    q.push({newRow, newCol});
                    reachAtlantic[newRow][newCol] = true;
                }
            }
        }
        
        vector <vector <int> > flowFromBoth;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(reachPacific[i][j] and reachAtlantic[i][j]){
                    flowFromBoth.push_back(vector <int> {i, j});
                }
            }
        }
        return flowFromBoth;
    }
};
