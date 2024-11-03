class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n=s.size();
        string orig=s;

        do{
            
            if(s==goal) return true;
            char ch=s[0];
            string temp=s.substr(1,n);

            temp+=ch;
            cout<<temp<<endl;
            s=temp;
        }while (s!=orig);
        return false;
        
    }
};