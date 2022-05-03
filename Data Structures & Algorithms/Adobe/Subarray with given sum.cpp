class Solution{
    public:
    vector<int> subarraySum(int arr[], int n, long long s){
        int l = 0, r = 0;
        long long currentSum = 0;
        while(l < n){
            while(r < n and currentSum < s){
                currentSum += arr[r++];
            }
            if(currentSum == s){
                return vector <int> {l + 1, r};
            }
            currentSum -= arr[l];
            ++l;
        }
        return vector <int> {-1};
    }
};
