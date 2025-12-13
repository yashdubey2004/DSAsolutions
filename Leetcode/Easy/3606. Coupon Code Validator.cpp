class Solution {
public:
    bool isValidCode(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!(isalnum(c) || c == '_')) return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> tempcode, templine;
        for (int i = 0; i < code.size(); i++) {
            if (isValidCode(code[i]) && isActive[i]) {
                if (businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant") {
                    tempcode.push_back(code[i]);
                    templine.push_back(businessLine[i]);
                }
            }
        }

        vector<string> elecresult, groresult, pharresult, resresult;
        for (int i = 0; i < templine.size(); i++) {
            if (templine[i] == "electronics") {
                elecresult.push_back(tempcode[i]);
            } else if (templine[i] == "grocery") {
                groresult.push_back(tempcode[i]);
            } else if (templine[i] == "pharmacy") {
                pharresult.push_back(tempcode[i]);
            } else if (templine[i] == "restaurant") {
                resresult.push_back(tempcode[i]);
            }
        }

        sort(elecresult.begin(), elecresult.end());
        sort(groresult.begin(), groresult.end());
        sort(pharresult.begin(), pharresult.end());
        sort(resresult.begin(), resresult.end());

        vector<string> finalans;
        finalans.insert(finalans.end(), elecresult.begin(), elecresult.end());
        finalans.insert(finalans.end(), groresult.begin(), groresult.end());
        finalans.insert(finalans.end(), pharresult.begin(), pharresult.end());
        finalans.insert(finalans.end(), resresult.begin(), resresult.end());

        return finalans;
    }
};
