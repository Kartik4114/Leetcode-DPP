class Solution {
public:
    unordered_map<string, vector<string>> buildAdj(string beginWord, vector<string>& wordList) {
        int m = wordList.size();
        int n = beginWord.size();
        unordered_map<string, vector<string>> adj;

        for (auto &word : wordList) {
            int diffChar = 0;
            for (int j = 0; j < n; j++) {
                if (beginWord[j] != word[j]) {
                    diffChar++;
                }
            }
            if (diffChar == 1) {
                adj[beginWord].push_back(word);
            }
        }

        for (int i = 0; i < m; i++) {
            string word = wordList[i];
            for (int j = i + 1; j < m; j++) {
                int diffChar = 0;
                for (int k = 0; k < n; k++) {
                    if (wordList[j][k] != word[k]) 
                        diffChar++;
                }
                if (diffChar == 1) {
                    adj[word].push_back(wordList[j]);
                    adj[wordList[j]].push_back(word);
                }
            }
        }

        return adj;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Step 1: Early exit if endWord not in wordList
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        // Step 2: Build adjacency list
        auto adj = buildAdj(beginWord, wordList);

        // Step 3: BFS with visited set
        unordered_set<string> visited;
        queue<string> que;
        que.push(beginWord);
        visited.insert(beginWord);

        int len = 1;
        while (!que.empty()) {
            int N = que.size();
            while (N--) {
                auto front = que.front();
                que.pop();

                if (front == endWord) return len;

                for (auto &v : adj[front]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        que.push(v);
                    }
                }
            }
            len++;
        }

        return 0; // return 0 if no transformation sequence exists
    }
};
