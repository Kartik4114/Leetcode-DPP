class Solution {
public:
    typedef priority_queue<int,vector<int>, greater<int>> min_queue;
    void storeElements(vector<int> &nums,min_queue &pq,unordered_map<int,int> &mp){
        int maxi=INT_MIN;
        int mini=INT_MAX;

        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }

        for(int i=mini;i<=maxi;i++){
            if(mp.find(i)==mp.end())
            pq.push(i);
        }

        if((pq.size())<nums.size()){

            int size_diff=nums.size()-(pq.size());

            while(size_diff>0){
                pq.push(maxi+1);
                size_diff--;
                maxi++;
            }
        }
    }

    int a1(vector<int> &nums){
            int n=nums.size();

        min_queue pq;
        sort(nums.begin(),nums.end());

        for(auto num:nums){
            cout<<num<<" ";
        }
        cout<<endl;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        storeElements(nums,pq,mp);

        int moves=0;
        for(int i=0;i<n;i++){
            while(mp[nums[i]]>1){

                if(nums[i]<pq.top()){
                    moves+=(pq.top()-nums[i]);
                    cout<<moves<<" ";
                    mp[nums[i]]--;
                }
                pq.pop();
            }
        }   

        return moves;   
    }
    int minIncrementForUnique(vector<int>& nums) {
        
        // APPROACH 1:- USING HEAPS AND UNORDERED MAP
        return a1(nums);
    }
};