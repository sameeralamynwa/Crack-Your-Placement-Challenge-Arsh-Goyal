class Solution {
public:
    int minEatingSpeed(vector <int> &piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low < high){
            int mid = (low + high) >> 1;
            int hoursRequired = 0;
            for(int i = 0; i < (int) piles.size(); ++i){
                hoursRequired += 1 + (piles[i] - 1) / mid;
            }
            hoursRequired <= h ? high = mid : low = mid + 1;
        }
        return low;
    }
};
