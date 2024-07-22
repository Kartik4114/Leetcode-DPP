class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int n=target.size();

        int result=0;

        int prev=0;
        for(int i=0;i<n;i++){
            int curr=target[i];

            if(abs(curr)>abs(prev)){
                result+=(abs(curr)-abs(prev));
            }
            prev=curr;
        }
        return result;
    }
};