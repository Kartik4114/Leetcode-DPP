class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n=s.size();
        string orig=s;
        
        int size=n;
        while(size>0){
            
            if(s==goal) return true;
            char ch=s[0];
            string temp=s.substr(1,n);

            temp+=ch;
            cout<<temp<<endl;
            s=temp;
            size--;
        }
        return false;
        
    }
};