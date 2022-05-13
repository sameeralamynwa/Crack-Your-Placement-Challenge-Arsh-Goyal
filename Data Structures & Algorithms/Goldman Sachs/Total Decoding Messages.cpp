class Solution {
    private:
    const int mod = 1e9 + 7;

    public:
    int CountWays(string s){
	    int n = s.size();
	    vector <int> dp(n);
	    for(int i = 0; i < n; ++i){
	        if(i == 0){
	            dp[i] = s[i] != '0';
	        }
	        else{
	            if(stoi(s.substr(i - 1, 2)) >= 10 and stoi(s.substr(i - 1, 2)) <= 26){
	                dp[i] = i - 2 >= 0 ? dp[i - 2] : 1;
	            }
	            dp[i] += (s[i] != '0') * dp[i - 1];
	        }
	        dp[i] %= mod;
	    }
	    return dp[n - 1];
	}
};
