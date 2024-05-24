class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        int n=arr.size();
        vector<pair<int,int>> temp(n);

        for(int i=0;i<n;i++){
            int set_bit=__builtin_popcount(arr[i]);
            temp[i].first=set_bit;
            temp[i].second=arr[i];

        }

        sort(temp.begin(),temp.end());

        vector<int> result;
        for(int i=0;i<n;i++){
            result.push_back(temp[i].second);
        }
        return result;
    }
};