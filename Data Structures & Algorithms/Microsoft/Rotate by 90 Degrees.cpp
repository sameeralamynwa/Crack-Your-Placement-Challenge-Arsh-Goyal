void rotate(vector <vector <int> > &matrix){
    for(vector <int> &rows : matrix){
        reverse(rows.begin(), rows.end());
    }
    for(int row = 0; row < (int) matrix.size(); ++row){
        for(int col = 0; col < (int) matrix.size(); ++col){
            if(row < col){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
}
