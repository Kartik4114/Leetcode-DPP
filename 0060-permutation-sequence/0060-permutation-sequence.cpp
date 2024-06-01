class Solution {
public:
    string getPermutation(int n, int k) {
        
        // APPROACH 1:- USING RECURSION (TLE) IT WILL GIVE TLE
        // HERE T.C:- O(n*2^n)

        // APPROACH 2:- OPTIMISED APPROACH 
        // T.C :- O(N^2) // BEC. OF USING ERASE FUNCTION IN WHILE LOOP
        
        int fact=1;
        vector<int> numbers;
        for(int i=1;i<n;i++){
            fact=fact*i;
            numbers.push_back(i);
        }

        numbers.push_back(n);
        string ans="";
        k=k-1;
        while(true){
            ans+= to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact); // O(n)
            if(numbers.size()==0) break;

            k=k%fact;
            fact=fact/numbers.size();
        }
        return ans;
    }
};