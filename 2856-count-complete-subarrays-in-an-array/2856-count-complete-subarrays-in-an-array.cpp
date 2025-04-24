class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        int n=nums.size();
        unordered_set<int> st(nums.begin(),nums.end());

        int result=0;
        for(int i=0;i<n;i++){
            
            set<int> subSt;
            for(int j=i;j<n;j++){

                subSt.insert(nums[j]);

                if(subSt.size()==st.size()){
                    result+=(n-j);
                    break;
                }
            }
        }

        return result;
    }
};