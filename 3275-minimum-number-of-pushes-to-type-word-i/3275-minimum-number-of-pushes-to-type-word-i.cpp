class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> arr(26,0);
        for(auto ch:word){
            arr[ch-'a']++;
        }

        sort(arr.begin(),arr.end(),greater<int>());
        int impact=1;
        int cnt=arr[0];

        for(int i=1;i<arr.size();i++){
            
            if(i%8==0) impact++;
            cnt+=arr[i]*impact;
        }
        return cnt;
    }
};