class Solution {
public:
    bool isArraySpecial(vector<int>& arr) {
        
        // bool check=true;
        
        for(int i=0;i<arr.size()-1;i++){
            
            if(((arr[i]%2==1) && (arr[i+1]%2==1)) || ((arr[i]%2==0) && (arr[i+1]%2==0)))  return false;
        }
        
        return true;
    }
};