class Solution {
public:
    int myAtoi(string s) {
        
        int n=s.size();

        int idx=s.find_first_not_of(" ");

        if(idx<0) return 0;

        bool sign=false;

        if(s[idx]=='-') sign=true;
        if(s[idx]=='-' || s[idx]=='+') idx++;
        

        long long ans=0;
        for(int i=idx;i<s.size();i++){

            if(s[i]>='0' && s[i]<='9'){

                ans=(long long)ans*10+(s[i]-'0');

                if(sign==false){
                    if(ans>=INT_MAX) return INT_MAX;
                } else {
                    if(-ans<=INT_MIN) return INT_MIN;
                }
                cout<<ans<<endl;
            } else break;
        }

        return sign==true ? -ans : ans;

    }
};