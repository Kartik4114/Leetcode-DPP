class Solution {
public:
    int a1(string s) {
        
        int n=s.size();

        set<char> letters(s.begin(),s.end());

        int result=0;
        for(auto &letter:letters){

            int leftIdx=-1;
            int rightIdx=-1;

            for(int i=0;i<n;i++){

                if(s[i]==letter){

                    if(leftIdx==-1){
                        leftIdx=i;
                    } 

                    rightIdx=i;
                }
            }

            set<char> st;
            for(int middle=leftIdx+1;middle<=rightIdx-1;middle++){
                st.insert(s[middle]);
            }

            result+=st.size();

        }

        return result;
    }
    int a2(string s) {
        int n=s.size();

        vector<pair<int,int>> indices(26,{-1,-1});

        for(int i=0;i<n;i++){

            char ch=s[i];
            int idx=ch-'a';

            if(indices[idx].first==-1){
                indices[idx].first=i;
            }
            indices[idx].second=i;
        }

        int result=0;

        for(int i=0;i<26;i++){

            if(indices[i]== make_pair(-1,-1)) continue;

            set<char> st;
            for(int middle=indices[i].first+1;middle<=indices[i].second-1;middle++){
                st.insert(s[middle]);
            }

            result+=st.size();
        }

        return result;
    }
    int countPalindromicSubsequence(string s) {
        
        // APPROACH 1:-
        // T.C :- O(n) , S.C:- O(26) ~ O(1)
        // return a1(s);

        // APPROACH 2:-
        // T.C :- O(n) , S.C:- O(26) ~ O(1)
        return a2(s);
    }
};