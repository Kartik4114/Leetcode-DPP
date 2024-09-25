class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<string> st;

        for(int i=0;i<arr1.size();i++){

            string temp=to_string(arr1[i]);
            for(int j=0;j<temp.size();j++){

                string toInsert=temp.substr(0,j+1);
                st.insert(toInsert);
            }
        }

        int maxLen=0;
        for(int i=0;i<arr2.size();i++){

            string arrStr=to_string(arr2[i]);

            int n=arrStr.size();
            for(int j=n;j>=0;j--){

                string temp=arrStr.substr(0,j+1);
                
                if(st.find(temp)!=st.end()){
                    cout<<temp.size()<<endl;
                    int size=temp.size();
                    maxLen=max(maxLen,size);
                    break;
                }
            }
        }

        return maxLen;
    }
};