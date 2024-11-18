class Solution {
public:
    vector<int> prevKSum(vector<int> &arr,int k){
        
        int n=arr.size();

        vector<int> result;
        for(int i=n-1;i>=n/2;i--){

            int sumIdx=0;
            for(int j=i-1;j>i+(k-1);j--){
                sumIdx+=arr[j];
            }
            cout<<sumIdx<<" ";
            result.push_back(sumIdx);
        }

        reverse(result.begin(),result.end());
        return result;
    }

    vector<int> nextKSum(vector<int> &arr,int k){

        int n=arr.size();

        vector<int> result;
        for(int i=0;i<n/2;i++){

            int sumIdx=0;
            for(int j=i+1;j<i+k+1;j++){
                sumIdx+=arr[j];
            }
            result.push_back(sumIdx);
        }

        return result;
    }
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n=code.size();

        vector<int> temp=code;
        for(auto &c:code) temp.push_back(c);

        if(k < 0){
            return prevKSum(temp,k);
        }

        else if(k==0){
            vector<int> result(n,0);
            return result;
        }
        
        return nextKSum(temp,k);
    }
};