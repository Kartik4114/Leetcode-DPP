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

    string a1(string &expression){
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

    string a2(string &expr){

        int nume=0;
        int deno=1;

        int i=0;
        int n=expr.length();
        while(i<n){

            int currNume=0;
            int currDeno=0;

            bool isNeg=(expr[i]=='-');

            if(expr[i]=='+' || expr[i]=='-') i++;

            //Build the currNume
            while(i<n && isdigit(expr[i])){
                int val=expr[i]-'0';
                currNume=(currNume*10) +val;
                i++;
            }

            i++; //numerator / denominator //skipiing the divisrio character '/'
            
            if(isNeg==true) currNume*=-1;

            //Build the currDeno
            while(i<n && isdigit(expr[i])){
                int val=expr[i]-'0';
                currDeno=(currDeno*10) +val;
                i++;
            }

            nume=nume*currDeno + deno*currNume;
            deno=deno*currDeno;
        }

        //num
        //deno
        //-3 / 6 //GCD : 3
        int GCD=abs(__gcd(nume,deno));

        nume/=GCD;
        deno/=GCD;

        return to_string(nume) + '/' + to_string(deno);
    }
    string fractionAddition(string expr) {
        
        // APPROACH 1:-
        // T.C :- O(n) , S.C :- O(n)
        // return a1(expr);

        // APPROACH 2:-
        // T.C :- O(n) , S.C :- O(1)
        return a2(expr);
    }
};