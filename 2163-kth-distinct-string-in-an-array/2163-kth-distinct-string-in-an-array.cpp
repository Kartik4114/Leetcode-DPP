class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        int n=arr.size();
        unordered_map<string,int> mp;
        for(auto a:arr){
            mp[a]++;
        }

        for(int i=0;i<n;i++){
            if(mp[arr[i]]==1) k--;
            if(k==0){
                return arr[i];
            }
        }
        return "";
    }
};