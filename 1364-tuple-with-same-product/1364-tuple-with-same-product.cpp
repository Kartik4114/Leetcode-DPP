class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> productCount;
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) { // Avoid duplicate pairs
                int product = nums[i] * nums[j];
                if (productCount.find(product) != productCount.end()) {
                    cnt += productCount[product]; // Count the valid tuples
                }
                productCount[product]++; // Store the product count
            }
        }

        return cnt * 8; // Each valid pair corresponds to 8 valid tuples (as order matters)
    }
};
