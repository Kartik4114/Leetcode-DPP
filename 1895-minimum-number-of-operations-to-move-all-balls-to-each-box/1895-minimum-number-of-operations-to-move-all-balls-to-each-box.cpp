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

        vector<int> tempForward(n,0);

        int cntOne=0;

        tempForward[0]=0;
        if(boxes[0]=='1') cntOne++;
        for(int i=1;i<n;i++){

            tempForward[i]=cntOne+tempForward[i-1];
            if(boxes[i]=='1') cntOne++;
        }

        vector<int> tempBackward(n,0);

        cntOne=0;

        tempBackward[n-1]=0;
        if(boxes[n-1]=='1') cntOne++;
        for(int i=n-2;i>=0;i--){

            tempBackward[i]=cntOne+tempBackward[i+1];
            if(boxes[i]=='1') cntOne++;
        }

        vector<int> result(n,0);

        for(int i=0;i<n;i++){

            result[i]=tempForward[i]+tempBackward[i];
        }

        return result;

    }
    vector<int> minOperations(string boxes) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH 
        // T.C :- O(N^2)
        // return a1(boxes);

        // APPROACH 2:- OPTIMIsED APPROACH
        return a2(boxes);

    }
};