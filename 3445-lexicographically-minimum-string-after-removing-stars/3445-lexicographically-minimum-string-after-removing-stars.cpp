class Solution {
public:

    // void a1(string &s){

    //     int n = s.size();
    //     map<char, set<int>> mp;

    //     for (int i = 0; i < n; i++) {
    //         if (s[i] == '*') {
    //             // Find the smallest character in the map (lexicographically)
    //             auto& st = mp.begin()->second; // Use reference so original set is modified
    //             auto it = prev(st.end());      // Get last inserted index
    //             s[*it]='*';

    //             st.erase(it);    
    //             if (st.empty()) {
    //                 mp.erase(mp.begin());      // Remove char entry if no indices left
    //             }
    //         } else {
    //             mp[s[i]].insert(i); // Track index for each character
    //         }
    //     }

    // }
    
    typedef pair<char,int> P; 
    
    class comp{
        
        public: 
            bool operator()(P &p1,P &p2){
                if(p1.first==p2.first){
                    return p1.second<p2.second;
                }

                return p1.first>p2.first;
            }
    };

    void a2(string &s){

        int n=s.size();

        priority_queue<P,vector<P>,comp> pq;

        for(int i=0;i<n;i++){

            if(s[i]=='*'){

                auto top=pq.top();
                pq.pop();

                int idx=top.second;
                s[idx]='*';
            } else {
                pq.push({s[i],i});
            }
        }

    }
    string clearStars(string s) {
        
        // APPROACH 1:- USING MAP (CHAR+SET) 
        // T.C :- O(NLOGN) , S.C :- O(N)
        // a1(s);

        // APPROACH 2:- USING priority queue 
        // T.C :- O(NLOGN) , S.C :- O(N)
        a2(s);

        string result="";
        for(auto &ch:s){
            
            if(ch!='*'){
                result+=ch;
            }
        }
        return result;
    }
};
