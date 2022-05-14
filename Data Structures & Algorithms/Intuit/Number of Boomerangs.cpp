class Solution {
public:
    int distanceSquared(int x, int y, vector <vector <int> > &points){
        return (points[x][0] - points[y][0]) * (points[x][0] - points[y][0]) + (points[x][1] - points[y][1]) * (points[x][1] - points[y][1]);
    }
    
    int nChoseTwo(int n){
        return n * (n - 1) >> 1;
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), boomerangs = 0;
        for(int i = 0; i < n; ++i){
            map <int, int> atDistance;
            for(int j = 0; j < n; ++j){
                atDistance[distanceSquared(i, j, points)]++;
            }
            for(map <int, int> :: iterator it = atDistance.begin(); it != atDistance.end(); ++it){
                boomerangs += 2 * nChoseTwo(it -> second);
            }
        }
        return boomerangs;
    }
};
