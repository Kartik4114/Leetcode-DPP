class Solution {
public:

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        vector<pair<int,int>> store;

        for(int i=0;i<n;i++){
            
            int oldNum=nums[i];
            int cnt=0;
            int newNum=0;
            if(oldNum==0){
                newNum=mapping[0];
            }
            else {
                while(nums[i]>0){

                    int numModulo=nums[i]%10;

                    int newNumModulo=mapping[numModulo]*pow(10,cnt);
                    newNum+=newNumModulo;
                    cnt++;
                nums[i]=nums[i]/10;
                }
            }

            store.push_back(make_pair(newNum,oldNum));
        }

        auto lambda=[&](pair<int,int> p1,pair<int,int> p2){
            
            if(p1.first<p2.first) return p1<p2;
            else if(p1.first>p2.first) return p2>p1;
            else {
                return mp[p1.second]<mp[p2.second];
            }
            
        };
        sort(store.begin(),store.end(),lambda);

        vector<int> result;

        for(int i=0;i<n;i++){
            result.push_back(store[i].second);
        }
        return result;
    }
};