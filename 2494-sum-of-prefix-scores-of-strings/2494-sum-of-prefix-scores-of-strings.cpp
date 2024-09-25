class Solution {
public:
    struct trieNode{
        trieNode* children[26];
        int count=0;
    };

    trieNode* getNode(){

        trieNode* node=new trieNode();
        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }
        node->count=0;
        return node;
    }

    void insert(string &temp,trieNode* root){
        trieNode* pCrawler=root;

        for(int i=0;i<temp.size();i++){
            
            int idx=temp[i]-'a';
            if(pCrawler->children[idx]==NULL){
                pCrawler->children[idx]=getNode();
            }

            pCrawler=pCrawler->children[idx];
            pCrawler->count++;
        }
    }

    int getResult(string &temp,trieNode* root){

        trieNode* pCrawler=root;
        int score=0;

        for(int i=0;i<temp.size();i++){
            
            int idx=temp[i]-'a';

            if(pCrawler->children[idx]!=NULL){
                
                pCrawler=pCrawler->children[idx];
                score+=pCrawler->count;
            }  else break;
        }

        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        
        trieNode* root=getNode();

        for(int i=0;i<words.size();i++){
            insert(words[i],root);
        }

        vector<int> result;
        for(auto &word:words){
            int count=getResult(word,root);
            result.push_back(count);
        }

        return result;
    }
};