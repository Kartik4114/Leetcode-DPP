class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;

        return gcd(b,a%b);
    }

    int convertNum(string &s,int i){
        
        string num="";
        while(i>=0 && (s[i]!='+' && s[i]!='-')){
            num+=s[i];
            i--;
        }
        // cout<<"i :- "<<i<<endl;
        reverse(num.begin(),num.end());
        int ans=stoi(num);
        return (i>=0 && s[i]=='-') ? -ans : ans;
    }

    int convertDeno(string &s,int i){
        
        string num="";
        int n=s.size();
        while(i<n && (s[i]!='+' && s[i]!='-')){
            num+=s[i];
            i++;
        }
        int ans=stoi(num);
        return ans;
    }
    string fractionAddition(string expression) {
        
        int n=expression.size();

        vector<int> num;
        vector<int> deno;

        long mul=1;
        for(int i=0;i<n;i++){

            if(expression[i]=='/'){
                int number=convertNum(expression,i-1);
                num.push_back(number);

                int denoNum=convertDeno(expression,i+1);
                deno.push_back(denoNum);
                mul*=denoNum;
            }
        }

        long sum=0;
        for(int i=0;i<num.size();i++){
            sum=sum+((long)num[i]*mul/deno[i]);
        }

        
        int gcdAns=gcd(abs(sum),mul);

        int numAns=sum/gcdAns;
        int denoAns=mul/gcdAns;

        string result="";

        string numStr=to_string(abs(numAns));
        string denoStr=to_string(denoAns);

        if(numAns<0){
            result+='-';
        }
        result+=numStr;
        result+='/';
        result+=denoStr;
        return result;
    }
};