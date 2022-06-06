class Solution {
    public:
    int maxProfit(int k, int n, int a[]) {
        vector <vector <vector <int> > > dp(n, vector <vector <int> > (k, vector <int> (2)));
        for(int i = 0; i < n; ++i){
            for(int transaction = 0; transaction < k; ++transaction){
                if(transaction == 0){
                    if(i == 0){
                        dp[i][transaction][0] = 0;
                        dp[i][transaction][1] = -a[i];
                    }
                    else{
                        dp[i][transaction][0] = max(dp[i - 1][transaction][0], dp[i - 1][transaction][1] + a[i]);
                        dp[i][transaction][1] = max(dp[i - 1][transaction][1], -a[i]);
                    }
                }
                else{
                    if(i == 0){
                        dp[i][transaction][0] = 0;
                        dp[i][transaction][1] = -accumulate(a, a + n, 0);
                    }
                    else{
                        dp[i][transaction][0] = max(dp[i - 1][transaction][0], dp[i - 1][transaction][1] + a[i]);
                        dp[i][transaction][1] = max(dp[i - 1][transaction][1], dp[i - 1][transaction - 1][0] - a[i]);              
                    }
                }
            }
        }
        
        int maxProfit = 0;
        for(int transaction = 0; transaction < k; ++transaction){
            maxProfit = max(maxProfit, dp[n - 1][transaction][0]);
        }
        
        return maxProfit;
    }
};
