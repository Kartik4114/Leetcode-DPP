class Solution {
public:
    int countLargestGroup(int n) {
        
        unordered_map<int,int> mp;

        int maxSize=0;

        for(int i=1;i<=n;i++){

            string s=to_string(i);

            int sum=0;
            for(auto &ch:s){
                sum+=ch-'0';
            }
            
            cout<<sum<<endl;

            mp[sum]++;
            maxSize=max(maxSize,mp[sum]);
        }
        
        cout<<maxSize;
        int result=0;
        for(auto &it:mp){

            if(it.second==maxSize){
                result++;
            }
        }

        return result;
    }
};