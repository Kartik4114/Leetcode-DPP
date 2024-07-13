class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int, pair<int, char>> storeDetails;
        int n = positions.size();

        for (int i = 0; i < n; i++) {
            storeDetails[positions[i]] = {healths[i], directions[i]};
        }

        vector<int> sortedPositions = positions;
        sort(sortedPositions.begin(), sortedPositions.end());
        stack<int> st;

        for (auto pos : sortedPositions) {
            while (!st.empty() && storeDetails[st.top()].second == 'R' && storeDetails[pos].second == 'L') {
                int topElement = st.top();
                if (storeDetails[topElement].first == storeDetails[pos].first) {
                    st.pop();
                    storeDetails.erase(topElement);
                    storeDetails.erase(pos);
                    break;
                } else if (storeDetails[topElement].first < storeDetails[pos].first) {
                    st.pop();
                    storeDetails[pos].first -= 1;
                } else {
                    storeDetails[topElement].first -= 1;
                    storeDetails.erase(pos);
                    break;
                }
            }
            if (storeDetails.count(pos) > 0) {
                st.push(pos);
            }
        }

        vector<int> result(n, -1);
        unordered_map<int, int> idxStore;
        for (int i = 0; i < n; i++) {
            idxStore[positions[i]] = i;
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();

            int idx = idxStore[top];
            result[idx] = storeDetails[top].first;
        }

        vector<int> survived;
        for (auto &v : result) {
            if (v != -1) {
                survived.push_back(v);
            }
        }

        return survived;
    }
};
