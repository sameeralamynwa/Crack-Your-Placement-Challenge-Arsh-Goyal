class Solution{
    public:
    string amendSentence (string s) {
        for(int i = 0; i < (int) s.size(); ++i){
            if(s[i] >= 'A' and s[i] <= 'Z'){
                s[i] = s[i] + 32;
                if(i > 0){
                    s.insert(s.begin() + i, ' ');
                }
            }
        }
        return s;
    }
};
