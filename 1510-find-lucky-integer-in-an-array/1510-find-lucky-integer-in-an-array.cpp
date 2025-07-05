class Solution {
public:
    int findLucky(vector<int>& arr) {
        // Step 1: Count frequency of each number using unordered_map
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        // Step 2: Find the largest lucky number
        int maxLucky = -1;
        
        // Iterate through all unique numbers and their frequencies
        for (auto& pair : freq) {
            int number = pair.first;
            int frequency = pair.second;
            
            // Check if this number is lucky (frequency == number)
            if (frequency == number) {
                // Update maxLucky if this lucky number is larger
                maxLucky = max(maxLucky, number);
            }
        }
        
        return maxLucky;
    }
};