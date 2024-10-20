class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char curr : expression) {
            if (curr == ',' || curr == '(')
                continue;  
            if (curr == 't' || curr == 'f' || curr == '!' ||
                curr == '&' || curr == '|') {
                st.push(curr);
            }
            else if (curr == ')') {
                bool hasTrue = false, hasFalse = false;
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topValue = st.top();
                    st.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }
                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};