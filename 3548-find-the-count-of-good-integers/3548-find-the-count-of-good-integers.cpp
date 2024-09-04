class Solution {
public:
    typedef long long ll;

    int ans;
    vector<ll> fact;
    unordered_map<string,int> vis; 

    string genPal(ll num,ll len){
        
        string s=to_string(num);
        string t=s.substr(0,len);
        reverse(t.begin(),t.end());

        s+=t;
        return s;
    }

    bool check(string &s,int k){
        ll val=0;

        for(int i=0;i<s.size();i++){

            ll curr=s[i]-'0';
            val=val*10+curr;
        }
        if(val%k==0) return true;
        return false;
    }

    ll count(string &s){

        vector<ll> fr(10,0);
        ll n=s.size();

        if(n==1) return 1;

        for(int i=0;i<s.size();i++){

            ll curr=s[i]-'0';
            fr[curr]++;
        }
        
        ll total=fact[n];
        string str="";
        
        for(int i=0;i<fr.size();i++){
            ll curr=fr[i];
            str+=('a'+curr);

            if(curr!=0) total/=fact[curr];
        }

        if(vis.find(str)!=vis.end()) return 0;

        vis[str]=1;
        
        if(fr[0]==0) return total;

        ll a=fact[n-1];
        a=a/fact[fr[0]-1];

        for(int i=1;i<fr.size();i++){
            ll curr=fr[i];

            if(curr!=0) a/=fact[curr];
        }


        ll result=total-a;
        return result;
    }
    void find(int pos,int num,int len,int stat,int k){

        if(pos==len){
            ll palinLen=0;

            if(stat==1){
                palinLen=len-1;
            } else palinLen=len;

            string s=genPal(num,palinLen);
            bool st=check(s,k);

            if(st) ans+=count(s);

            return;
        }

        if(pos==0) {

            for(int i=1;i<=9;i++){
                int tNum=num*10+i;
                find(pos+1,tNum,len,stat,k);
            }
        } else {
            for(int i=0;i<=9;i++){
                int tNum=num*10+i;
                
                find(pos+1,tNum,len,stat,k);
            }
        }
        return;
    }
    long long countGoodIntegers(int n, int k) {
        
        ans=0;
        fact.clear();
        vis.clear();

        ll len;
        ll curr=1;
        int stat=0;

        for(int i=1;i<=11;i++){
            fact.push_back(curr);
            curr*=i;
        }

        if(n%2==1) {
            len=n/2+1;
            stat=1;
        } else {
            len=n/2;
            stat=0;
        }

        find(0,0,len,stat,k);
        return ans;
    }
};