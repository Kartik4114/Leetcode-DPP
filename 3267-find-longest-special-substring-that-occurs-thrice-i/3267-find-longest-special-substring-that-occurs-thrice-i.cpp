class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int k = 1; 
        int j = 0; 

        while (k <= n) {
            int cnt = 1;
            if (j + k > n){
                return k - 1;
            } 
            string tmp = s.substr(j, k);
            bool oke = true;
            for (int i = 1; i < tmp.size(); i++) {
                if (tmp[i] != tmp[i - 1]) {
                    oke = false;
                    break;
                }
            }

            if (!oke) {
                j++;
                continue;
            }

            for (int i = j + 1; i < n; i++) {
                if (i + k > n) break; 
                if (s.substr(i, k) == tmp) cnt++;
            }

            if (cnt >= 3) { 
                k++;      
                j = 0;      
            } else {
                if (j == n - k) return k - 1 == 0 ? -1 : k - 1;
                else j++;
            }
        }
        return -1;
    }
};