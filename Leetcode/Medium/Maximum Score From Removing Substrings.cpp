class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalgain = 0;
        stack<char> st;
        char firstchar1, secondchar1, firstchar2, secondchar2;
        int currgain1, currgain2;
        if(y >= x){
            firstchar1 = 'b';
            secondchar1 = 'a';
            currgain1 = y;
            
            firstchar2 = 'a';
            secondchar2 = 'b';
            currgain2 = x;
        }
        else{
            firstchar1 = 'a';
            secondchar1 = 'b';
            currgain1 = x;
            
            firstchar2 = 'b';
            secondchar2 = 'a';
            currgain2 = y;
        }

        for(char c: s){
            if(!st.empty() && st.top() == firstchar1 && c == secondchar1){
                totalgain += currgain1;
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        string left = "";
        while (!st.empty()) {
            left += st.top();
            st.pop();
        }
        reverse(left.begin(), left.end());

        for(char c: left){
            if(!st.empty() && st.top() == firstchar2 && c == secondchar2){
                totalgain += currgain2;
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return totalgain;
    }
};
