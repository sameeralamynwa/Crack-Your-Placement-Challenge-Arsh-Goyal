class Solution{
public:
    vector <int> max_of_subarrays(int *nums, int n, int k){
        deque <int> candidates;
        vector <int> maxSlidingWindow;
        for(int i = 0; i < k; ++i){
            while(candidates.size() and nums[i] >= nums[candidates.back()]){
                candidates.pop_back();
            }
            candidates.push_back(i);
        }
        
        maxSlidingWindow.push_back(nums[candidates.front()]);
        
        for(int i = 0; i + k < n; ++i){
            if(candidates.size() and candidates.front() == i){
                candidates.pop_front();
            }
            
            while(candidates.size() and nums[i + k] >= nums[candidates.back()]){
                candidates.pop_back();
            }
            candidates.push_back(i + k);
            
            maxSlidingWindow.push_back(nums[candidates.front()]);
        }
        
        return maxSlidingWindow;
    }
};
