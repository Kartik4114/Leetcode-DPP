class Solution {
public:
    
    class Compare {
public:
    bool operator()(pair<char,int> below, pair<char,int> above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
 
        return false;
    }
    };
    string clearStars(string s) {
        
        int n=s.size();
        
        int cnt=0;
         priority_queue<pair<char,int>,vector<pair<char,int>>, Compare> pq;
        for(int i=0;i<n;i++){
            
            if(s[i]!='*'){
                pq.push({s[i],i});
            }
            if(s[i]=='*'){
                
                // while(!pq.empty() && cnt>0){
                //     pq.pop();
                //     cnt--;
                // }
                if(!pq.empty()){
                    pq.pop();
                } 
            }   
        }
        
        
        
        unordered_set<int> st;
        
        while(!pq.empty()){
            st.insert(pq.top().second);
            pq.pop();
        }
        
        string ans="";
        
        for(int i=0;i<n;i++){
            if(st.find(i)!=st.end()){
                ans+=s[i];
            }
        }
        
        return ans;
        
        
    
        
    }
};