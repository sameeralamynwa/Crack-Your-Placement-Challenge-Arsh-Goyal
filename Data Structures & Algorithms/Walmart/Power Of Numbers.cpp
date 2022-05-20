class Solution{
    public:
    long long power(int n, int r){
        int answer = 1;
        while(r > 0){
            if(r & 1){
                answer = (long long) answer * n % mod;
            }
            n = (long long) n * n % mod;
            n %= mod;
            r >>= 1;
        }
        return answer;
    }
};
