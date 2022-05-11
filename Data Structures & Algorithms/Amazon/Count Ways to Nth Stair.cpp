class Solution{
    public:
    long long countWays(int n){
        vector <long long> numOfWays(n + 1);
        for(int i = 1; i <= 2; ++i){
            for(int till = i; till <= n; ++till){
                if(till == i){
                    numOfWays[till] += 1;
                }
                else{
                    numOfWays[till] += numOfWays[till - i];
                }
            }
        }
        return numOfWays[n];
    }
};
