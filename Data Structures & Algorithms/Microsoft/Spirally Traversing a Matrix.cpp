class Solution{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
        vector <int> spiralTraversal;
        int totalElements = r * c;
        for(int start = 0; start < (r + 1) / 2; start++){
            int index = start;
            while(index < c - start and totalElements-- > 0){
                spiralTraversal.push_back(matrix[start][index++]);
            }
            index = start + 1;
            while(index < r - start and totalElements-- > 0){
                spiralTraversal.push_back(matrix[index++][c - start - 1]);
            }
            index = c - start - 2;
            while(index >= start and totalElements-- > 0){
                spiralTraversal.push_back(matrix[r - start - 1][index--]);
            }
            index = r - start - 2;
            while(index > start and totalElements-- > 0){
                spiralTraversal.push_back(matrix[index--][start]);
            }
        }
        return spiralTraversal;
    }
};
