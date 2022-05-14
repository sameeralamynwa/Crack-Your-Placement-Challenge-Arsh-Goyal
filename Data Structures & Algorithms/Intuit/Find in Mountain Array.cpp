class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), low = 1, high = n - 2, peak;
        while(low <= high){
            int mid = (low + high) >> 1, current = mountainArr.get(mid), previous = mountainArr.get(mid - 1), after = mountainArr.get(mid + 1);
            if(previous < current){
                if(current < after){
                    low = ++mid;
                }
                else{
                    peak = mid;
                    break;
                }
            }
            else{
                high = --mid;
            }
        }
        
        low = 0, high = peak;
        while(low <= high){
            int mid = (low + high) >> 1, current = mountainArr.get(mid);
            if(current == target){
                return mid;
            }
            else if(current < target){
                low = ++mid;
            }
            else{
                high = --mid;
            }
        }

        low = peak, high = n - 1;
        while(low <= high){
            int mid = (low + high) >> 1, current = mountainArr.get(mid);
            if(current == target){
                return mid;
            }
            else if(current > target){
                low = ++mid;
            }
            else{
                high = --mid;
            }
        }
        
        return -1;
    }
};
