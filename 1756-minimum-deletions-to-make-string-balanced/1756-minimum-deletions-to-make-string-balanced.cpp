class Solution {
public:
    int a1(string s){
        int n=s.size();
        stack<char> st;

        int cnt=0;
        for(int i=0;i<n;i++){

            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                st.pop();
                cnt++;
            }
            else st.push(s[i]);
        }
        return cnt;
    }

    int a2(string s){

        int n = s.size();

    if (n == 0) return 0; // Handle empty string case

    int cntRightOfA = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') cntRightOfA++;
    }

    if (cntRightOfA == 0 || cntRightOfA == n - 1) return 0;

    int minCnt = INT_MAX;
    int cntOfBLeft = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') cntRightOfA--;
        
        int toDelete = cntRightOfA + cntOfBLeft;
        minCnt = min(minCnt, toDelete);
        if (s[i] == 'b') cntOfBLeft++;
    }

    return minCnt;
    }
    int minimumDeletions(string s) {
        
        // Approach 1:- using stacks
        // Here we don't want which to delete we just have to increase the count
        // T.C :- O(n) , S.C :- O(n)

        // return a1(s);

        // Approach 2:- using simply simulating the array

        return a2(s);
    }
};