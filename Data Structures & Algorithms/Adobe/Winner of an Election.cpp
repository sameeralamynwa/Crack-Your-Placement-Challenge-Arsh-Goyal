class Solution{
    public:
    vector<string> winner(string arr[], int n) {
        int maxCount = 0;
        map <string, int> count;
        for(int i = 0; i < n; ++i){
            if(count.find(arr[i]) == count.end()){
                count.insert({arr[i], 1});
            }
            else{
                count[arr[i]]++;
            }
            maxCount = max(maxCount, count[arr[i]]);
        }
        for(auto it = count.begin(); it != count.end(); ++it){
            if(it -> second == maxCount){
                return vector <string> {it -> first, to_string(it -> second)};
            }
        }
    }
};
