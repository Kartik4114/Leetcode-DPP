class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Unique element found
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }

            // Case 1: pair is on the left
            if (((nums[mid] == nums[mid-1]) && (mid % 2 == 1)) || 
                ((nums[mid] == nums[mid+1]) && (mid % 2 == 0))){
                low=mid+1;
            } else {
                high=mid-1;
            }
            
        }

        return -1; // should never happen
    }
};
