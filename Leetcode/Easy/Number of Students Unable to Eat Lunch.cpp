class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;
        bool cycle = false;

        while(students.size() > 0 && sandwiches.size() > 0 && !cycle){
            
            if(students[0] == sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                count = 0;
            }
            else{
                int num = students[0];
                students.erase(students.begin());
                students.push_back(num);
                count++;
            }

            if(count == students.size()){
                cycle = true;
            }
        }

        return students.size();
    }
};
