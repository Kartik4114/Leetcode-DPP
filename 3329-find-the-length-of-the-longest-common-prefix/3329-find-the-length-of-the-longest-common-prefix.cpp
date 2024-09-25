class Solution {
public:
    int a1(vector<int> &arr1,vector<int> &arr2){
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

    struct trieNode{
        trieNode *children[10];
    };
    
    trieNode* getNode(){
        trieNode* node=new trieNode();
        for(int i=0;i<10;i++){
            node->children[i]=NULL;
        }
        return node;
    }
    void insert(int num,trieNode* root){

        trieNode* pCrawler=root;

        string temp=to_string(num);

        int n=temp.size();
        for(int i=0;i<n;i++){

            int idx=temp[i]-'0';

            if(pCrawler->children[idx]==NULL){
                pCrawler->children[idx]=getNode();
            }
            pCrawler=pCrawler->children[idx];
        }
    }

    int search(int num,trieNode* root){

        string temp=to_string(num);
        int n=temp.size();

        trieNode* pCrawler=root;

        int count=0;
        for(int i=0;i<n;i++){

            int idx=temp[i]-'0';
            if(pCrawler->children[idx]!=NULL){
                count++;
                pCrawler=pCrawler->children[idx];
            }

            else break;
        }
        return count;
    }

    int a2(vector<int> &arr1,vector<int> &arr2){

        trieNode* root=getNode();
        
        for(int i=0;i<arr1.size();i++){
            insert(arr1[i],root);
        }

        int result=0;
        for(int i=0;i<arr2.size();i++){

            int count=search(arr2[i],root);
            result=max(result,count);
        }
        return result;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        // approach 1:- using unordered map and storing in the string
        // T.C :- O((m+n)*d) n=arr1.size(), m=arr2.size() , d:- no.of digits
        // return a1(arr1,arr2);

        // Approach 2:- Using trie
        return a2(arr1,arr2);

    }
};