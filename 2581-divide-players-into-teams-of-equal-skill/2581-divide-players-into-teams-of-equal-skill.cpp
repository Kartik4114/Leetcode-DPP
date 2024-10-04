class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n=skill.size();

        int sum=0;
        for(auto &s:skill) sum+=s;

        
        int modulo=sum%(n/2);

        if(modulo!=0) return -1;
        // cout<<modulo<<endl;

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++) {
            mp[skill[i]]++;
        }

        long long ans=0;
        int pairSum=sum/(n/2);

        for(auto &it:mp){

            while(it.second>0){
                
                it.second--;
                if(mp[pairSum-it.first]>0){
                    long long sum=it.first*(long long)(pairSum-it.first);
                    ans+=sum;
                    mp[pairSum-it.first]--;
                } else return -1;
            }

        }
        return ans;
    }
};