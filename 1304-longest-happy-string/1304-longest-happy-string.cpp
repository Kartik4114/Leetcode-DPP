class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string result = "";

        if(pq.size() == 0) return "";

        while(pq.size() > 1){

            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            if(freq >= 2) {

                if(result.size()>0 && result[result.size()-1]==ch){
                    result+=ch;
                    freq--;
                }
                else {
                    result += ch;
                    result += ch;
                    freq -= 2;
                }
            } else {
                result += ch;
                freq -= 1;
            }

            int nextCharFreq = pq.top().first;
            char nextChar = pq.top().second;
            pq.pop();

            if(nextCharFreq > 0) {
                result += nextChar;
                nextCharFreq--;
            }

            if(nextCharFreq > 0) pq.push({nextCharFreq, nextChar});
            if(freq > 0) pq.push({freq, ch});
        }

        if(!pq.empty()) {
            int lastAdd = pq.top().first;
            char lastAddChar = pq.top().second;

            if(lastAdd >= 2) {
                result += lastAddChar;
                result += lastAddChar;
            } else if(lastAdd == 1) {
                result += lastAddChar;
            }
        }

        return result;
    }
};
