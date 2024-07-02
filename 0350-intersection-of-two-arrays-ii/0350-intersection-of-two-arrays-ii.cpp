class Solution {
public:
    vector<int> a1(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        int m=nums2.size();
        vector<int> result;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i]<nums2[j]){
                i++;
            } else {
                j++;
            }
        }

        return result;
    }

    vector<int> a2(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,int> mp;
        vector<int> result;

        for(auto num:nums1){
            mp[num]++;
        }

        for(auto num:nums2){
            if(mp[num]>0){
                result.push_back(num);
                mp[num]--;
            }
        }
        return result;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        // APPROACH 1:- USING SORTING AND TRAVERSING (BEST APPROACH)
        // T.C:- O(nlogn) ,S.C :- O(1)
        // return a1(nums1,nums2);

        // APPROACH 2:- USING MAP
        // T.C:- O(n) ,S.C :- O(n)
        return a2(nums1,nums2);


    }
};