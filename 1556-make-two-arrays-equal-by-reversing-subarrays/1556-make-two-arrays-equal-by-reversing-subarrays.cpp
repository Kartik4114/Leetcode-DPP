class Solution {
public:
    bool a1(vector<int> &target,vector<int> &arr){

        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=target[i]) return false;
        }
        return true;
    }

    bool a2(vector<int> &target,vector<int> &arr){
        
        unordered_map<int,int> mp;
        for(auto &t:target){
            mp[t]++;
        }

        int n=arr.size();
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==0){
                cout<<"Enter"<<" ";
                return false;
            }
            cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
            mp[arr[i]]--;
        }
        return true;
    }
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        // APPROACH 1:- using sorting 
        // T.C :- O(nlogn) , S.C :- O(1)
        // return a1(target,arr);

        // APPROACH 2:- using map
        // T.C :- O(n) , S.C :- O(n)
        return a2(target,arr);
    }
};