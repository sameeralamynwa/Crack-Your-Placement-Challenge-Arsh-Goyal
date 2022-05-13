class Solution{
    public:
    string colName (long long int n){
        string column;
        while(n > 0){
            long long newN = n, times = 1;
            while(newN > 26){
                newN = (newN - 1) / 26;
                times *= 26;
            }
            n = n - newN * times;
            column.push_back('A' + newN - 1);
        }
        return column;
    }
};
