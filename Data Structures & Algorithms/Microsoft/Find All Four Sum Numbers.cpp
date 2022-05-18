class Solution{
    public:
    vector <vector <int> > fourSum(vector <int> &arr, int k) {
        sort(arr.begin(), arr.end());
        vector <vector <int> > qudadruples;
        for(int first = 0; first < (int) arr.size(); ++first){
            if(first > 0 and arr[first] == arr[first - 1]){
                continue;
            }
            for(int second = first + 1; second < (int) arr.size(); ++second){
                if(second > first + 1 and arr[second] == arr[second - 1]){
                    continue;
                }
                int target = k - arr[first] - arr[second], third = second + 1, fourth = (int) arr.size() - 1;
                while(third < fourth){
                    if(third > second + 1 and arr[third] == arr[third - 1]){
                        third++;
                        continue;
                    }
                    if(arr[third] + arr[fourth] == target){
                        qudadruples.push_back(vector <int> {arr[first], arr[second], arr[third], arr[fourth]});
                        third++;
                        fourth--;
                    }
                    else if(arr[third] + arr[fourth] < target){
                        third++;
                    }
                    else{
                        fourth--;
                    }
                }
            }
        }
        return qudadruples;
    }
};
