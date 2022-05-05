class Solution {
public:
    int maxCoins(vector<int> &a, int n){
        vector <vector <vector <int> > > dp(n, vector <vector <int> > (n, vector <int> (2)));
        for(int i = 0; i < n; ++i){
            dp[i][i][0] = a[i];
        }
        for(int length = 2; length <= n; ++length){
            for(int i = 0; i + length - 1 < n; ++i){
                int j = i + length - 1;
                dp[i][j][0] = a[j] + dp[i][j - 1][1];
                dp[i][j][0] = max(dp[i][j][0], a[i] + dp[i + 1][j][1]);
                
                dp[i][j][1] = min(dp[i][j - 1][0], dp[i + 1][j][0]);
            }
        }
        return dp[0][n - 1][0];
    }
};
