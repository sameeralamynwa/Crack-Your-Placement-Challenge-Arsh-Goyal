bool solve(int pos, bool missingOccured, int lastNumber, string s, int &numberMissing){
    if(pos == (int) s.size()){
        return true;
    }
    bool possible = false;
    if(pos == 0){
        for(int len = 1; len <= min((int) s.size(), 6); len++){
            possible |= solve(len, false, stoi(s.substr(0, len)), s, numberMissing);
        }
    }
    else{
        string toForm = to_string(++lastNumber);
        if(s.substr(pos, (int) toForm.size()) == toForm){
            possible = solve(pos + (int) toForm.size(), missingOccured, lastNumber, s, numberMissing);
        }
        else{
            if(missingOccured == false){
                toForm = to_string(++lastNumber);
                if(s.substr(pos, (int) toForm.size()) != toForm){
                    return false;
                }
                else{
                    lastNumber--;
                    numberMissing = lastNumber;
                    lastNumber++;
                    possible = solve(pos + (int) toForm.size(), true, lastNumber, s, numberMissing);
                }
            }
            else{
                return false;
            }
        }
    }
    return possible;
}

int missingNumber(const string& s){
    int numberMissing = -1;
    if(solve(0, false, -1, s, numberMissing)){
        return numberMissing;
    }
    else{
        return -1;
    }
}
