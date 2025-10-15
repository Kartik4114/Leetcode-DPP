class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        
        vector<pair<int, int>> v;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[j] < nums[j + 1]) j++;
            
            if (j > i) v.push_back({i, j});
            i = j + 1;
        }
        
        for(int i=0;i<v.size();i++){
            
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        
        
        int result=0;
        for (int i = 0; i < v.size(); i++) {
            int f = v[i].first;
            int s = v[i].second;
            
            int diff1=abs(s-f+1);
            
                result=max(result,diff1/2);
            
            if (i + 1 < v.size()) {
                int f1 = v[i + 1].first;
                int s1 = v[i + 1].second;
                
                
                int diff2=abs(s1-f1+1);
                
                result=max(result,diff2/2);
                
                if(s+1==f1){
                    int minDiff=min(diff1,diff2);
                    result=max(result,minDiff);
                }
                
            }
        }
        if(result==0) return 1;
        return result;
    }
};