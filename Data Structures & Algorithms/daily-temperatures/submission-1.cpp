class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        stack<int> st;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            auto temp = temperatures[i];
            // Continously POP the stack elements if temp[st.top()] <= curr temp.
            while (!st.empty() && temperatures[st.top()] <= temp) {
                st.pop();
            }
            (st.empty()) ? res.push_back(0) : res.push_back(st.top() - i);
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};