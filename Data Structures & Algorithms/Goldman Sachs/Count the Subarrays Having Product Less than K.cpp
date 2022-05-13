class Solution{
    public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int l = 0, r = 0;
        long long product = 1, subarrays = 0;
        while(l < n){
            while(r < n and product < k){
                product *= a[r++];
            }
            if(product >= k){
                subarrays += r - l - 1;
            }
            else{
                subarrays += r - l;
            }
            product /= a[l++];
        }
        return subarrays;
    }
};
