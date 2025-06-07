class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        map<char, set<int>> mp;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                // Find the smallest character in the map (lexicographically)
                auto& st = mp.begin()->second; // Use reference so original set is modified
                auto it = prev(st.end());      // Get last inserted index
                s[*it]='*';
                
                st.erase(it);    
                if (st.empty()) {
                    mp.erase(mp.begin());      // Remove char entry if no indices left
                }
            } else {
                mp[s[i]].insert(i); // Track index for each character
            }
        }

        // vector<pair<int,int>> temp;

        // for(auto &[ch,indices]:mp){
        //     for(auto &idx:indices){
        //         temp.push_back({idx,ch});
        //     }
        // }

        // sort(temp.begin(),temp.end());

        string result="";
        for(auto &ch:s){
            
            if(ch!='*'){
                result+=ch;
            }
        }

        return result;
    }
};
