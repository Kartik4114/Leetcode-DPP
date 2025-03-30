class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n=s.size();
        
        unordered_map<char,int> mp;
        for(auto &ch:s){
            mp[ch]++;
        }

        set<int> st;
        vector<int> result;
        int sizeCnt=0;
        for(int i=0;i<n;i++){

            st.insert(s[i]);
            mp[s[i]]--;
            sizeCnt++;

            if(mp[s[i]]==0){
                st.erase(s[i]);
                mp.erase(s[i]);

                if(st.size()==0){
                    result.push_back(sizeCnt);
                    sizeCnt=0;
                }
            }
        }

        return result;
    }
};