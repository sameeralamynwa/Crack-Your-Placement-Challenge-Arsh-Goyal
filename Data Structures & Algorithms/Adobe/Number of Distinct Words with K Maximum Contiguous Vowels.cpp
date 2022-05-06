class Solution{
    private:
    const int mod = 1e9 + 7;
    public:
    int kvowelwords(int n, int k) {
        vector <vector <int> > dp(n, vector <int> (k + 1));
        for(int i = 0; i < n; ++i){
            for(int atmost = 0; atmost <= k; ++atmost){
                if(atmost == 0){
                    if(i == 0){
                        dp[i][atmost] = 21;
                    }
                    else{
                        dp[i][atmost] = (long long) 21 * dp[i - 1][k] % mod;
                    }
                }
                else{
                    if(i == 0){
                        dp[i][atmost] = 26;
                    }
                    else{
                        dp[i][atmost] = (long long) 5 * dp[i - 1][atmost - 1] % mod + (long long) 21 * dp[i - 1][k] % mod;
                        dp[i][atmost] %= mod;
                    }
                }
            }
        }
        return dp[n - 1][k];
    }
