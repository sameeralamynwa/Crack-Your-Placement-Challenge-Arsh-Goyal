class Solution {
    public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        vector <int> occurs(k);
        for(int x : nums){
            occurs[x % k]++;
        }
        for(int i = 1; i < k; ++i){
            if(i == k - i and occurs[i] % 2 != 0){
                return false;
            }
            else if(occurs[i] != occurs[k - i]){
                return false;
            }
        }
        return n % 2 == 0;
    }
};
