class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // Process the asteroid
            while (!st.empty() && st.top() > 0 && ast[i] < 0) {
                // Check collision cases
                if (abs(st.top()) == abs(ast[i])) {
                    st.pop(); // Both asteroids destroy each other
                    ast[i] = 0; // Mark current asteroid as destroyed
                    break;
                } else if (abs(st.top()) < abs(ast[i])) {
                    st.pop(); // Top asteroid is destroyed, continue checking
                } else {
                    ast[i] = 0; // Current asteroid is destroyed
                    break;
                }
            }
            // Push current asteroid if it survives
            if (ast[i] != 0) {
                st.push(ast[i]);
            }
        }

        // Prepare the result
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
