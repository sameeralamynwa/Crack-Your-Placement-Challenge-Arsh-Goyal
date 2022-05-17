class Solution{
    public:
    void solve(int key, int *a, int n, string possibleWord, vector <vector <int> > &keypad, vector <string> &allCombinations){
        if(key >= n){
            allCombinations.push_back(possibleWord);
            return;
        }
        for(int possibleCharacter : keypad[a[key]]){
            solve(key + 1, a, n, possibleWord + char ('a' + possibleCharacter), keypad, allCombinations);
        }
    }
    
    vector<string> possibleWords(int a[], int n){
        vector <vector <int> > keypad{
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {9, 10, 11},
            {12, 13, 14},
            {15, 16, 17, 18},
            {19, 20, 21},
            {22, 23, 24, 25}
        };
        for(int i = 0; i < n; ++i){
            a[i] -= 2;
        }
        vector <string> allCombinations;
        solve(0, a, n, "", keypad, allCombinations);
        return allCombinations;
    }
};
