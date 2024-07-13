class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int, pair<int, char>> mp;
        int n = positions.size();

        for (int i = 0; i < n; i++) {
            mp[positions[i]] = {healths[i], directions[i]};
        }

        vector<int> temp = positions;
        sort(positions.begin(), positions.end());
        stack<int> st;

        for (auto &pos : positions) {
            while (!st.empty() && mp[st.top()].second == 'R' && mp[pos].second == 'L') {
                int topElement = st.top();
                if (mp[topElement].first == mp[pos].first) {
                    st.pop();
                    mp.erase(topElement);
                    mp.erase(pos);
                    break;
                } else if (mp[topElement].first < mp[pos].first) {
                    st.pop();
                    mp[pos].first -= 1;
                } else {
                    mp[topElement].first -= 1;
                    mp.erase(pos);
                    break;
                }
            }
            if (mp.count(pos)) st.push(pos);
        }

        vector<int> result(n, -1);
        unordered_map<int, int> idxStore;

        for (int i = 0; i < n; i++) {
            idxStore[temp[i]] = i;
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();

            int idx = idxStore[top];
            result[idx] = mp[top].first;
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
