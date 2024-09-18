class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // Define a lambda function to use as the comparison function
        auto lambda = [](int a, int b) {
            int cntBit_a = __builtin_popcount(a);
            int cntBit_b = __builtin_popcount(b);

            // If the count of set bits is the same, sort by value
            if (cntBit_a == cntBit_b) {
                return a < b;
            }
            // Otherwise, sort by the count of set bits
            return cntBit_a < cntBit_b;
        };

        // Sort the array using the lambda function
        sort(arr.begin(), arr.end(), lambda);

        // Return the sorted array
        return arr;
    }
};
