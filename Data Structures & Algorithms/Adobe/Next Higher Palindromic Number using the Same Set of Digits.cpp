class Solution{
  public:
    string nextPalin(string n) {
        int i = (int)  n.size() / 2 - 1;
        while(i > 0 and n[i - 1] >= n[i]){
            --i;
        }
        if(i <= 0){
            return "-1";
        }
        else{
            --i;
            for(char c = n[i] + 1; c <= '9'; ++c){
                for(int j = i + 1; j < (int) n.size() / 2; ++j){
                    if(n[j] == c){
                        swap(n[i], n[j]);
                        swap(n[(int) n.size() - i - 1], n[(int) n.size() - j - 1]);
                        sort(n.begin() + i + 1, n.begin() + (int) n.size() / 2);
                        sort(n.begin() + (int) (n.size() + 1) / 2, n.begin() + (int) n.size() - i - 1);
                        reverse(n.begin() + (int) (n.size() + 1) / 2, n.begin() + (int) n.size() - i - 1);
                        return n;
                    }
                }
            }
        }
    }
};
