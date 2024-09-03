class Solution {
public:
    string strToInt(string s,int k){
        int n=s.size();

        string result="";
        for(auto &ch:s){
            int num=ch-'a'+1;
            string strNum=to_string(num);
            result+=strNum;
        }
        return result;
    }
    int getLucky(string s, int k) {
        
        string num=strToInt(s,k);

        int ans=0;

        while(k>0){
            
            int currAns=0;
            for(int i=0;i<num.size();i++){
                int a=num[i]-'0';
                currAns+=a;
            }

            ans=currAns;
            num=to_string(currAns);
            k--;
        }
        return ans;
    }
};