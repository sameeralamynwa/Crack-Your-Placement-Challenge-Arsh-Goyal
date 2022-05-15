class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size(), g = __gcd(n, m);
        for(int maybe = 1; maybe * maybe <= g; ++maybe){
            if(g % maybe == 0){
                int window = g / maybe;
                bool possible = true;
                for(int i = 0; i < min(m, n); ++i){
                    possible &= str1[i] == str2[i];
                }
                for(int i = 0; i + window < m; ++i){
                    possible &= str2[i] == str2[i + window];
                }
                for(int i = 0; i + window < n; ++i){
                    possible &= str1[i] == str1[i + window];
                }
                if(possible){
                    return str2.substr(0, window);
                }
            }
        }

        for(int maybe = 1; maybe * maybe <= g; ++maybe){
            if(g % maybe == 0){
                int window = maybe;
                bool possible = true;
                for(int i = 0; i < min(m, n); ++i){
                    possible &= str1[i] == str2[i];
                }
                for(int i = 0; i + window < m; ++i){
                    possible &= str2[i] == str2[i + window];
                }
                for(int i = 0; i + window < n; ++i){
                    possible &= str1[i] == str1[i + window];
                }
                if(possible){
                    return str2.substr(0, window);
                }
            }
        }
        return "";
    }
};
