class Solution {
public:
    bool check(vector<int>& nums, int idx, int dir) {
        int n = nums.size();
        vector<int> temp = nums;

        while (idx >= 0 && idx < n) {
            if (temp[idx] == 0) {
                idx += dir; // Move in the current direction
            } else {
                temp[idx]--;   // Decrement the value
                dir *= -1;     // Reverse the direction
                idx += dir;    // Move in the new direction
            }
        }

        // Check if all elements become 0
    //     cout << "Temp array: ";
    // for (int val : temp) cout << val << " ";
    // cout << endl;

        for (int i = 0; i < n; i++) {
            if (temp[i] > 0) return false;
        }
        
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        // Iterate over all indices to find positions with value 0
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // Check validity for both directions
                if (check(nums, i, -1)) {
                    // cout<<i<<endl;
                    result++; 
                }
                if(check(nums,i,1)){
                    result++;
                }
            }
        }
        return result;
    }
};
