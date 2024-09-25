class Trie {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode(){

        trieNode* newNode=new trieNode();
        bool isEndOfWord=false;

        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    trieNode*root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        
        trieNode* pCrawler=root;
        for(int i=0;i<word.size();i++){

            char ch=word[i];
            int idx=ch-'a';

            if(pCrawler->children[idx]==NULL){
                pCrawler->children[idx]=getNode();
            }
            pCrawler=pCrawler->children[idx];
        }
        pCrawler->isEndOfWord=true;
    }
    
    bool search(string word) {
        
        trieNode* pCrawler=root;

        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';

            if(pCrawler->children[idx]==NULL) return false;
            pCrawler=pCrawler->children[idx];

        }
        if(pCrawler!=NULL && pCrawler->isEndOfWord==false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        
        trieNode* pCrawler=root;

        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
            int idx=ch-'a';

            if(pCrawler->children[idx]==NULL) return false;
            pCrawler=pCrawler->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */