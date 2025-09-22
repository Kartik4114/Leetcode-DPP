class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
    
    // APPROACH 1:- TWO PASS APPROACH BEC. WE ARE TRAVERSING MAP TWO TIMES
    // REMEMBER WE CAN USE ARRAY BEC. CONSTRAINT ARE VERY LESS THEN IT WILL BECOME O(1) BEC.
    // ARRAY SIZE WILL BE 100
        // map<int,int> mp;
        // for(auto num:nums) mp[num]++;

        // int max=-1;
        // for(auto it:mp){
        //     if(it.second>max) max=it.second;
        // }

        // int freq=0;
        // for(auto it:mp){
        //     if(it.second==max) freq+=max;
        // }
        // return freq;

    // APPROACH 2:- ONE PASS APPROACH 
        int max_freq=0;
        int total=0;

        int arr[101]={0};

        for(auto &num:nums){
            arr[num]++;

            if(arr[num]>max_freq){
                max_freq=arr[num];
                total=max_freq;
            }

            else if(arr[num]==max_freq){
                total+=arr[num];
            }
        }

        return total;
    }
};