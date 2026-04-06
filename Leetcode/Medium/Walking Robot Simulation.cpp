class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        unordered_set<string> st;
        for(int i = 0; i < obstacles.size(); i++){
            st.insert(to_string(obstacles[i][0]) + "#" + to_string(obstacles[i][1])); // FIX 2
        }

        int x = 0, y = 0;
        int dir = 0; // 0 = north, 1 = east, 2 = south, 3 = west
        int maxdist = 0;

        for(int i = 0; i < commands.size(); i++){
            
            if(commands[i] == -1){
                dir = (dir + 1) % 4;
            }
            else if(commands[i] == -2){
                dir = (dir + 3) % 4;
            }
            else{
                int steps = commands[i]; 

                while(steps--){ 
                    
                    int nx = x;
                    int ny = y;

                    if(dir == 0) ny++;
                    else if(dir == 1) nx++;
                    else if(dir == 2) ny--;
                    else nx--;

                    if(st.count(to_string(nx) + "#" + to_string(ny))){
                        break;
                    }

                    x = nx;
                    y = ny;
                    maxdist = max(maxdist, x*x + y*y);
                }
            }
        }
        return maxdist;
    }
};
