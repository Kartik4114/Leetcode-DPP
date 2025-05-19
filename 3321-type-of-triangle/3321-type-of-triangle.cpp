#include <vector>
#include <algorithm> // for sort
#include <string>

using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums.size() < 3) {
            return "Invalid input: Less than three elements.";
        }

        sort(nums.begin(), nums.end()); // Sort sides in ascending order

        if(nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        else if(nums[0] + nums[1] <= nums[2]) {
            return "none"; // Not a valid triangle
        }
        else if(nums[0] != nums[1] && nums[1] != nums[2]) {
            return "scalene"; // All sides are different
        }
        else{
            return "isosceles"; // Two sides are equal
        }
    }
};
