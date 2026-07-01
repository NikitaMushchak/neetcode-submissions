class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> openToClosed {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        stack<char> opened;

        for (auto ch: s) {
            if (!openToClosed.count(ch)) 
            { // closed bracket
                if (!opened.empty() && ch == openToClosed[opened.top()]) {
                    opened.pop();
                } else {
                    return false;
                }
            } 
            else {
                // open bracket
                opened.push(ch);
            }
        }
        return opened.empty();
    }
};
