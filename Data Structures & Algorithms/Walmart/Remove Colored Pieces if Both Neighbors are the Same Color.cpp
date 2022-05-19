class Solution {
public:
    bool winnerOfGame(string colors) {
        int scoreA = 0, scoreB = 0;
        for(int i = 1; i + 1 < (int) colors.size(); ++i){
            if(colors[i] == 'A'){
                scoreA += colors[i - 1] == colors[i + 1] and colors[i - 1] == 'A';
            }
            else{
                scoreB += colors[i - 1] == colors[i + 1] and colors[i - 1] == 'B';
            }
        }
        return scoreA > scoreB;
    }
};
