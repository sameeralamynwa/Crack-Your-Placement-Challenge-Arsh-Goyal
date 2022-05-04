class Solution{
    public:
    bool solve(int pos, int n, int *arr, int remainingSum, vector <vector <int> > &dp){
        if(pos == n){
            return remainingSum == 0;
        }
        
        if(remainingSum < 0){
            return false;
        }
        
        if(dp[pos][remainingSum] != -1){
            return dp[pos][remainingSum];
        }
        
        return dp[pos][remainingSum] = solve(pos + 1, n, arr, remainingSum, dp) or solve(pos + 1, n, arr, remainingSum - arr[pos], dp);
    }
    int equalPartition(int n, int arr[]){
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += arr[i];
        }
        vector <vector <int> > dp(n, vector <int> (sum / 2 + 1, -1));
        return sum % 2 == 0 and solve(0, n, arr, sum >> 1, dp);
    }
};
