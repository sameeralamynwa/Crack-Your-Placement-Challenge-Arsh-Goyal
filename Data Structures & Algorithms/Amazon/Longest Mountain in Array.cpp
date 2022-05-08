class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), mountain = 1, maxMountain = 0;
        for(int i = 1; i < n; ++i){
            if(arr[i] == arr[i - 1]){
                mountain = 1;
            }
            else if(arr[i] > arr[i - 1]){
                mountain++;
            }
            else if(mountain > 1){
                int j = i;
                while(j < n and arr[j] < arr[j - 1]){
                    ++j;
                    mountain++;
                }
                i = j - 1;
                maxMountain = max(maxMountain, mountain);
                mountain = 1;
            }
        }
        return maxMountain;
    }
};
