string convertToBinary(int n){
    string binary;
    while(n > 0){
        binary.push_back(n & 1 ? '1' : '0');
        n >>= 1;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

vector<string> generate(int n){
    vector <string> allInBinary;
    for(int i = 1; i <= n; ++i){
        allInBinary.push_back(convertToBinary(i));
    }
    return allInBinary;
}
