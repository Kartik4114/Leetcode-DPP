class Solution {
public:
    int solve(string &boxes,int i){

        int n=boxes.size();

        int count=0;

        for(int j=0;j<n;j++){

            if(boxes[j]=='1'){
                count+=abs(j-i);
            }
        }
        return count;
    }

    vector<int> a1(string &boxes){

        int n=boxes.size();

        vector<int> result(n,0);

        for(int i=0;i<n;i++){

            int val=solve(boxes,i);
            result[i]=val;
        }

        return result;
    }

    vector<int> a2(string &boxes){

        int n=boxes.size();

        vector<int> answer(n,0);

        int currValueSum=0;
        int cumValue=0;

        for(int i=0;i<n;i++){
            answer[i]=currValueSum;

            cumValue+= boxes[i]=='0' ? 0 :1;
            currValueSum+=cumValue;
        }

        currValueSum=0;
        cumValue=0;

        for(int i=n-1;i>=0;i--){
            answer[i]+=currValueSum;

            cumValue+= boxes[i]=='0' ? 0 :1;
            currValueSum+=cumValue;
        }

        return answer;
    }
    vector<int> minOperations(string boxes) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH 
        // T.C :- O(N^2)
        // return a1(boxes);

        // APPROACH 2:- OPTIMISED APPROACH
        // T.C :- O(N) , S.C :- O(1)
        return a2(boxes);

    }
};