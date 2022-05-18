class Solution{
    public:
    vector <int> calculateSpan(int price[], int n){
        vector <int> leftGreaterIndex(n);
        stack <int> leftGreater;
        for(int i = 0; i < n; ++i){
            if(leftGreater.empty()){
                leftGreater.push(i);
                leftGreaterIndex[i] = -1;
            }
            else{
                while(leftGreater.empty() == false and price[i] >= price[leftGreater.top()]){
                    leftGreater.pop();
                }
                leftGreaterIndex[i] = leftGreater.empty() ? -1 : leftGreater.top();
                leftGreater.push(i);
            }
        }
        vector <int> span;
        for(int i = 0; i < n; ++i){
            if(leftGreaterIndex[i] == -1){
                span.push_back(i + 1);
            }
            else{
                span.push_back(i - leftGreaterIndex[i]);
            }
        }
        return span;
    }
};
