class Solution{
    public:
    int FindMaxSum(int arr[], int n){
        int yesterday = 0, dayBeforeYesterday = 0, today = 0;
        for(int days = 0; days < n; ++days){
            today = max(yesterday, dayBeforeYesterday + arr[days]);
            dayBeforeYesterday = yesterday;
            yesterday = today;
        }
        return today;
    }
};
