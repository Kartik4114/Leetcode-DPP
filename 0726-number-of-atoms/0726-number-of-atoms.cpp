class Solution {
public:
    string countOfAtoms(string formula) {
        
        int n=formula.size();
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());


        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            } else if(formula[i]==')'){
                auto curr=st.top();
                st.pop();
                i++;

                string mult="";
                while(i<n && isdigit(formula[i])){
                    mult+=formula[i];
                    i++;
                }

                if(!mult.empty()){
                    int multiInteger=stoi(mult);

                    for(auto &it:curr){
                        string element=it.first;
                        int count=it.second;

                        curr[element]=count*multiInteger;
                    }
                }

                // merging this to the stack top element to remove if another same element is present

                for(auto &it:curr){
                    string element=it.first;
                    int count=it.second;
                    st.top()[element]+=count;
                }

            } else{
                string currElement="";
                currElement+=formula[i];
                i++;

                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    currElement+=formula[i];
                    i++;
                }

                string currCount="";
                while(i<n && isdigit(formula[i])){
                    currCount+=formula[i];
                    i++;
                }

                
                int currCountInteger=currCount.empty() ? 1 : stoi(currCount);
                
                st.top()[currElement]+=currCountInteger;            }
        }
        
        map<string,int> mp(st.top().begin(),st.top().end());
        string result="";

        for(auto &it: mp){

            string element=it.first;
            int count=it.second;

            result+=element;

            if(count>1) result+=to_string(count);
        }
        return result;

    }
};