class Solution {
private:
    vector <int> dx {-1, 1, 0, 0}, dy{0, 0, -1, 1};

public:
    bool isValid(int row, int col, vector <vector <char> > &board){
        return row >= 0 and col >= 0 and row < board.size() and col < board[0].size();
    }

    void solve(int pos, int row, int col, vector <vector <int> > &vis, vector <vector <char> > &board, string word, bool &exists){
        if(exists or pos == (int) word.size()){
            exists = true;
            return;
        }
        for(int i = 0; i < 4; ++i){
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if(isValid(newRow, newCol, board) and vis[newRow][newCol] == false and board[newRow][newCol] == word[pos]){
                vis[newRow][newCol] = true;
                solve(pos + 1, newRow, newCol, vis, board, word, exists);
                vis[newRow][newCol] = false;
            }
        }
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        bool exists = false;
        vector <vector <int> > vis((int) board.size(), vector <int> (board[0].size()));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                solve(0, i, j, vis, board, word, exists);
            }
        }
        return exists;
    }
};
