class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;

        // Count the frequency of remainders when dividing by k
        for (auto &num : arr) {
            int arrMod = (num % k + k) % k; // Handle negative numbers properly
            mp[arrMod]++;
        }

        // Iterate through the map to check if pairs can be formed
        for (auto &it : mp) {
            int rem = it.first;
            int complement = (k - rem) % k; // Complement remainder to sum up to a multiple of k

            // Special case for remainder 0
            if (rem == 0) {
                if (mp[rem] % 2 != 0) {
                    return false;
                }
            }
            // Special case for k/2 when k is even
            else if (2 * rem == k) {
                if (mp[rem] % 2 != 0) {
                    return false;
                }
            } 
            // Check if the remainder count matches its complement
            else {
                if (mp[rem] != mp[complement]) {
                    return false;
                }
            }
        }

        return true;
    }
};
