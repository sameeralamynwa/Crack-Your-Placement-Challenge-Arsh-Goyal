class Solution{
    private:
    const int mod = 1e9 + 7;
    public:
    int power(int x, int n, int res = 1){
        while(n > 0){
            if(n & 1){
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
    
    int numOfWays(int n, int x){
        vector <vector <int> > dp(2, vector <int> (n + 1));
        dp[0][0] = dp[1][0] = 1;
        for(int i = 1; power(i, x) <= n; ++i){
            for(int j = 0; j <= n; ++j){
                if(j - power(i, x) >= 0){
                    dp[1][j] += dp[0][j - power(i, x)];
                    dp[1][j] %= mod;
                }
            }
            dp[0] = dp[1];
        }
        return dp[1][n];
    }
};
