class Solution {
public:
    bool a1(vector<int> &nums){
        int n=nums.size();

        for(int i=0;i<n;i++){

            for(int j=0;j<n-i-1;j++){
                
                if(nums[j]<=nums[j+1]) continue;
                
                int setBit1=__builtin_popcount(nums[j]);
                int setBit2=__builtin_popcount(nums[j+1]);

                if(setBit1==setBit2 && nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                } else return false;
            }
        }

        return true;
    }

    bool a2(vector<int> &nums){

        int n=nums.size();

        vector<pair<int,int>> vec;

        int i=0;
        while(i<n){

            int minEl=nums[i];
            int maxEl=nums[i];
            
            while(i+1<n && (__builtin_popcount(nums[i]) == __builtin_popcount(nums[i+1]))){
                minEl=min(minEl,nums[i+1]);
                maxEl=max(maxEl,nums[i+1]);
                i++;
            }

            vec.push_back({minEl,maxEl});
            i++;
        }

        for(int i=0;i<vec.size()-1;i++){

            int currRegionMax=vec[i].second;
            int nextRegionMin=vec[i+1].first;

            cout<<currRegionMax<<" "<<nextRegionMin<<endl;
            if(currRegionMax > nextRegionMin) return false;
        }
        return true;
    }
    bool canSortArray(vector<int>& nums) {
        
        // APPROACH 1:- USING BUBBLE SORT 
        // T.C :- O(N^2) , S.C :- O(N)
        // return a1(nums);

        // APPROACH 2:- USING SEGMENT SORTING
        // T.C :- O(N) 
        return a2(nums);
    }
};