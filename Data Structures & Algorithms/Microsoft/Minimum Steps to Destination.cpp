int sumTillN(int n){
    return n * (n + 1) / 2;
}

class Solution{
    public:
    int minSteps(int d){
        for(int steps = 1; ; ++steps){
            if(sumTillN(steps) % 2 == d % 2 and sumTillN(steps) >= d){
                return steps;
            }
        }
    }
};
