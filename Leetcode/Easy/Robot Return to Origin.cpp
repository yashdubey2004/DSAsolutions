class Solution {
public:
    bool judgeCircle(string moves) {
        int uc = 0, dc = 0, dr = 0, dl = 0;
        for(int i = 0; i < moves.length(); i++){
            if(moves[i] == 'U') uc++;
            else if(moves[i] == 'D') dc++;
            else if(moves[i] == 'R') dr++;
            else dl++;
        }
        if(uc == dc && dr == dl) return true;
        return false;
    }
};
