class Solution {
public:
    int mod=1e9+7;
    int a1(vector<int>& nums, int n, int left, int right){
        vector<int> temp;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                temp.push_back(sum);
            }
        }

        sort(temp.begin(),temp.end());
        
        int result=0;

        for(int i=left-1;i<right;i++){
            result=(result+temp[i])%mod;
        }
        return result;
    }

    typedef pair<int,int> P;
    int a2(vector<int>& nums, int n, int left, int right){
        
        priority_queue<P,vector<P>,greater<P>> pq;

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        int result=0;
        for(int count=1;count<=right;count++){
            auto p=pq.top();
            pq.pop();

            int sum=p.first;
            int idx=p.second;

            if(count>=left){
                result=(result+sum)%mod;
            }

            int new_idx=idx+1;
            P newPair;
            if(new_idx<n){
                newPair.first=sum+nums[new_idx];
                newPair.second=new_idx;
                pq.push(newPair);
            }
        }
        return result;
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        // approach 1:- O(n^2*logn)
        // return a1(nums,n,left,right);

        // Approach 2:- O(n^2*logn);
        return a2(nums,n,left,right);
    }
};