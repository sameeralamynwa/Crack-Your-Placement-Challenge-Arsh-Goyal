class Solution{
    public:
    int atoi(string str) {
        int number = 0, sign = 1;
        if(*str.begin() == '-'){
            sign = -1;
            str.erase(str.begin());
        }
        for(char c : str){
            if(c < '0' or c > '9'){
                return -1;
            }
            number *= 10;
            number += c - '0';
        }
        return sign * number;
    }
};
