class Solution{
    public:
    vector<int> leaders(int a[], int n){
        vector <int> leaders;
        int maxSoFar;
        for(int i = n - 1; i >= 0; --i){
            if(i == n - 1){
                leaders.push_back(a[i]);
                maxSoFar = a[i];
            }
            else{
                if(a[i] >= maxSoFar){
                    leaders.push_back(a[i]);
                }
                maxSoFar = max(maxSoFar, a[i]);
            }
        }
        reverse(leaders.begin(), leaders.end());
        return leaders;
    }
};
