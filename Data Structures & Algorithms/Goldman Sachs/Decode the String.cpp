class Solution {
public:
    string decodedString(string s){
        int howMany = 0;
        stack <char> segments;
        stack <int> count;
        for(char c : s){
            if(c >= '0' and c <= '9'){
                howMany *= 10;
                howMany += c - '0';
            }
            else if(c == '['){
                count.push(howMany);
                segments.push(c);
                howMany = 0;
            }
            else if(c == ']'){
                string pattern;
                while(segments.size() and segments.top() != '['){
                    pattern.push_back(segments.top());
                    segments.pop();
                }
                segments.pop();
                reverse(pattern.begin(), pattern.end());
                for(int i = 0; i < count.top(); ++i){
                    for(char c : pattern){
                        segments.push(c);
                    }
                }
                count.pop();
            }
            else{
                segments.push(c);
            }
        }
        string decoded;
        while(segments.size()){
            decoded += segments.top();
            segments.pop();
        }
        reverse(decoded.begin(), decoded.end());
        return decoded;
    }
};
