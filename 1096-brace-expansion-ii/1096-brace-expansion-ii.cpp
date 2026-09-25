class Solution {
public:

    set<string> parseFactor(string &s, int &i) {

        set<string> result;

        if (s[i] >= 'a' && s[i] <= 'z') {

            result.insert(string(1, s[i]));
            i++;
        }

        else if (s[i] == '{') {

            i++; 

            result = parseExpression(s, i);

            i++; 
        }

        return result;
    }


    set<string> parseTerm(string &s, int &i) {

        set<string> result;

        result.insert("");

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> current = parseFactor(s, i);

            set<string> temp;

            for (string a : result) {
                for (string b : current) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }


    set<string> parseExpression(string &s, int &i) {

        set<string> result = parseTerm(s, i);

        while (i < s.size() && s[i] == ',') {

            i++; 

            set<string> current = parseTerm(s, i);

            for (string x : current) {
                result.insert(x);
            }
        }

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parseExpression(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};