class Solution {
public:
    string maximumXor(string s, string t) {
        int count1t = 0, count0t = 0;
        for(char c : t){
            if(c == '1') count1t++;
            else count0t++;
        }
        int i = 0;
        string res = "";
        while(i < s.length()){   
            if(s[i] == '0'){
                if(count1t > 0){
                    res += '1';
                    count1t--;
                }
                else{
                    res += '0';
                    count0t--;
                }
            }
            else{ 
                if(count0t > 0){
                    res += '0';
                    count0t--;
                }
                else{
                    res += '1';
                    count1t--;
                }
            }

            i++;
        }
        string fin = "";
        for(int i = 0; i < res.length(); i++){
            if(res[i] != s[i]) fin += '1';
            else fin += '0';
        }

        return fin;
    }
};
