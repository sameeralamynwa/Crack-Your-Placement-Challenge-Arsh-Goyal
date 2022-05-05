class Solution{
    public:
    void solve(int pos, int openCount, int n, string currentSequence, vector <string> &allBalancedParenthesis){
        if(openCount < 0 or openCount > 2 * n - pos){
            return;
        }
        if(pos == 2 * n){
            if(openCount == 0){
                allBalancedParenthesis.push_back(currentSequence);
            }
            return;
        }
        solve(pos + 1, openCount + 1, n, currentSequence + "(", allBalancedParenthesis);
        solve(pos + 1, openCount - 1, n, currentSequence + ")", allBalancedParenthesis);
    }
    
    vector<string> AllParenthesis(int n) {
        vector <string> allBalancedParenthesis;
        solve(0, 0, n, "", allBalancedParenthesis);
        return allBalancedParenthesis;
    }
};
