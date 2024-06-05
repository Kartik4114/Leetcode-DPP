class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;

        // Initialize the frequency vector for the first word
        vector<int> temp(26, 0);
        for (char ch : words[0]) {
            temp[ch - 'a']++;
        }

        // Iterate over the rest of the words
        for (int i = 1; i < words.size(); i++) {
            vector<int> temp2(26, 0);
            for (char ch : words[i]) {
                temp2[ch - 'a']++;
            }
            // Update the temp vector with the minimum frequency found in the current word
            for (int j = 0; j < 26; j++) {
                temp[j] = min(temp[j], temp2[j]);
            }
        }

        // Collect the common characters
        for (int i = 0; i < 26; i++) {
            while (temp[i] > 0) {
                result.push_back(string(1, i + 'a'));
                temp[i]--;
            }
        }

        return result;
    }
};
