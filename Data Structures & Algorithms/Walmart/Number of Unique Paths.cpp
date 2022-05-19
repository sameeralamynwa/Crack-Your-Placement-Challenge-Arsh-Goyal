class Solution{
    public:
    int NumberOfPath(int a, int b){
        vector <vector <int> > numOfWays(a, vector <int> (b));
        for(int row = 0; row < a; ++row){
            for(int col = 0; col < b; ++col){
                if(row == 0 or col == 0){
                    numOfWays[row][col] = 1;
                }
                else{
                    numOfWays[row][col] = numOfWays[row - 1][col] + numOfWays[row][col - 1];
                }
            }
        }
        return numOfWays[--a][--b];
    }
};
