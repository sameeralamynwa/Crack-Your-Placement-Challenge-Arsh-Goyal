class Solution{
    public:
    bool solve(int pos, string s, string pattern, string &sequence){
        if(pos == (int) s.size()){
            sequence = pattern;
            return true;
        }
        if(pos == -1){
            for(char maybe = '1'; maybe <= '9'; ++maybe){
                if(solve(pos + 1, s, pattern + maybe, sequence)){
                    return true;
                }
            }
        }
        else if(s[pos] == 'I'){
            for(char maybe = pattern.back() + 1; maybe <= '9'; ++maybe){
                if(find(pattern.begin(), pattern.end(), maybe) == pattern.end() and solve(pos + 1, s, pattern + maybe, sequence)){
                    return true;
                }
            }
        }
        else{
            for(char maybe = '1'; maybe < pattern.back(); ++maybe){
                if(find(pattern.begin(), pattern.end(), maybe) == pattern.end() and solve(pos + 1, s, pattern + maybe, sequence)){
                    return true;
                }
            }
        }
        return false;
    }
    
    string printMinNumberForPattern(string s){
        string sequence;
        solve(-1, s, "", sequence);
        return sequence;
    }
};
