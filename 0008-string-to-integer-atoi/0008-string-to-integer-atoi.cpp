class Solution {
public:

    long long num;
    void solve(string &temp,int idx ,bool sign){
        int n=temp.size();
        if(idx>=n){
            return;
        }
        
        
        num=num*10+(temp[idx]-'0');
        if(num>=INT_MAX && sign==false){
            num= INT_MAX;
                        cout<<"b"<<endl;

            return;
        }
        if(-num<=INT_MIN && sign==true){
            num= INT_MIN;
            cout<<"a"<<endl;
            return;
        }

        solve(temp,idx+1,sign);
    }
    int myAtoi(string s) {
        
        if(s.size()==0) return 0;
        string temp;
        int idx=s.find_first_not_of(" ");
        
        if(idx<0) return 0;
        cout<<idx<<endl;
        bool sign =false;
        if(s[idx]=='-') sign=true;
        if(s[idx]=='-' || s[idx]=='+') idx++;

        for(int i=idx;i<s.size();i++){

            if(s[i]>='0' && s[i]<='9'){
                temp.push_back(s[i]);
            }

            else break;
        }

        int n=temp.size();
        
        if(n==0) return 0;
        num=0;
        solve(temp,0,sign);



        if(sign==true)
        cout<<"True"<<endl;
        else cout<<"False"<<endl;

        if(num==INT_MIN && sign==true) return INT_MIN;
        if(num==INT_MAX && sign ==false) return INT_MAX;
        if(sign==true){
            // num=-num;
            // if(num<INT_MIN)  return INT_MIN ;
            cout<<"sign"<<endl;
            return -num;
        }
    
        // if(num>INT_MAX) return INT_MAX;
        return num;
    }
};