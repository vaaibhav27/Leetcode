
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;

        for (string word : words) {
            string target;

            char ch = tolower(word[0]);

            if (row1.find(ch) != string::npos) {
                target = row1;
            }
            else if (row2.find(ch) != string::npos) {
                target = row2;
            }
            else {
                target = row3;
            }

            bool valid = true;

            for (char c : word) {
                c = tolower(c);

                if (target.find(c) == string::npos) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
