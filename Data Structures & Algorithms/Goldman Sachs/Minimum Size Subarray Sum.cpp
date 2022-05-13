class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), minSubarray = n + 1;
        long long sum = 0;
        while(l < n){
            while(r < n and sum < target){
                sum += nums[r++];
            }
            if(sum >= target){
                minSubarray = min(minSubarray, r - l);
            }
            sum -= nums[l++];
        }
        return minSubarray == n + 1 ? 0 : minSubarray;
    }
};
