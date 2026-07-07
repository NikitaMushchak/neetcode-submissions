class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operation;
        int res = 0;
        for (const string & token: tokens) {
            if (isNumerical(token)) {
                cout << "token: " << token << endl;
                operation.push(stoi(token));
            } else {
                int a = operation.top();
                operation.pop();
                int b = operation.top();
                operation.pop();
                if (token == "+") {
                    operation.push(b + a);
                }
                else if (token == "-") {
                    operation.push(b - a);
                }
                else if (token == "*") {
                    operation.push(b * a);
                }
                else if (token == "/") {
                    operation.push(b / a);
                }
            }
        }
        return operation.top();
    }
private:
    bool isNumerical(string str) {
        if (str.empty()) {
            return false;
        }

        for (char c: str) {
            if (c == '-') {
                continue;
            }
            if (isdigit(c)) {
                return true;
            }
        }
        return false;
    }
};
