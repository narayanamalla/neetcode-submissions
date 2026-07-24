class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {

            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {

                int first = st.top();
                st.pop();

                int second = st.top();
                st.pop();

                switch (tokens[i][0]) {

                    case '+':
                        st.push(second + first);
                        break;

                    case '-':
                        st.push(second - first);
                        break;

                    case '*':
                        st.push(second * first);
                        break;

                    case '/':
                        st.push(second / first);
                        break;
                }
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};