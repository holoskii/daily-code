//https://leetcode.com/problems/valid-parenthesis-string/
bool checkValidString(string s) {
        int lower = 0, upper = 0;
        for (char c : s) {
            if (c == '(') {
                lower++;
                upper++;
            }
            else if (c == ')') {
                lower--;
                upper--;
            }
            else if (c == '*') {
                lower--;
                upper++;
            }
            if (upper < 0)
                return 0;
            if (lower < 0) lower = 0;
        }
        //cout << lower << " " << depth << " " << upper << endl;
        if (lower == 0) return 1;
        return 0;
    }
