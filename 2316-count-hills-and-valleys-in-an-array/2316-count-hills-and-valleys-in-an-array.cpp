class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> temp;

        for(int i=0;i<n-1;i++){
            
            if(nums[i]!=nums[i+1]){
                temp.push_back(nums[i]);
                cout<<temp.back()<<" ";
            }
        }
        cout<<endl;
        temp.push_back(nums[n-1]);

        int cnt=0;

        for(int i=1;i<temp.size()-1;i++){

            if((temp[i]>temp[i-1] && temp[i]>temp[i+1]) || (temp[i]<temp[i-1] && temp[i]<temp[i+1])){
                cnt++;
            } 
        }

        return cnt;
    }
};