class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        auto lambda=[](int &a,int &b){
            
            string s1=to_string(a);
            string s2=to_string(b);

            if(s1+s2>s2+s1) return true;
            return false;
        };

        sort(nums.begin(),nums.end(),lambda);

        if(nums[0]==0) return "0";

        string result="";

        for(auto &num:nums){

            string s=to_string(num);
            result+=s;
        }
        return result;
    }
};