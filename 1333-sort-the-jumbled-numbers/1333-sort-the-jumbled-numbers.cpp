class Solution {
public:
    string getMappedNum(string &num,vector<int> &mapping){
        string mappedNum=""; // O(d)
        for(int i=0;i<num.length();i++){
            char ch=num[i];
            int intCh=ch-'0';
            mappedNum+=to_string(mapping[intCh]);
        }
        return mappedNum;
    }
    vector<int> a1(vector<int>& mapping, vector<int>& nums){

        int n=nums.size();

        vector<pair<int,int>> vec; // O(n)

        for(int i=0;i<n;i++){ // O(n*d)

            string numStr=to_string(nums[i]); // O(d)
            string mappedStr=getMappedNum(numStr,mapping); // O(d)

            int mappedNum=stoi(mappedStr); // O(d)
            vec.push_back({mappedNum,i});
        }

        sort(vec.begin(),vec.end()); // O(nlogn)

        vector<int> result;
        for(auto &p:vec){
            int originalNumIdx=p.second;
            result.push_back(nums[originalNumIdx]);
        }
        return result;
    }

    int getMappedNum_a2(int num,vector<int> &mapping){
        
        if(num<10) return mapping[num];

        int mappedNum=0;
        int placeValue=1;

        while(num){
            int lastDigit=num%10;
            int mappedDigit=mapping[lastDigit];

            mappedNum+=(mappedDigit*placeValue);
            placeValue*=10;
            num/=10;
        }
        return mappedNum;
    }
    vector<int> a2(vector<int>& mapping, vector<int>& nums){

        int n=nums.size();

        vector<pair<int,int>> vec; // O(n)

        for(int i=0;i<n;i++){ // O(n*d)
            int mappedNum=getMappedNum_a2(nums[i],mapping); // O(d)
            vec.push_back({mappedNum,i});
        }

        sort(vec.begin(),vec.end()); // O(nlogn)

        vector<int> result;
        for(auto &p:vec){
            int originalNumIdx=p.second;
            result.push_back(nums[originalNumIdx]);
        }
        return result;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        // APPROACH 1:- converting num into string
        // S.C :- O(n+d) , T.C :- O(n*d + nlogn) 
        // d :- no.of digits in a number
        // return a1(mapping,nums);

        // APPROACH 2:- converting num directly into mapped num using modulo
        // OPTIMIZATION IN SPACE
        // S.C :- O(n) , T.C :- O(n*d + nlogn) 
        return a2(mapping,nums);
    
    }
};