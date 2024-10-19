#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void makeString(int n, string &temp) {

        if (n <= 1) {
            temp += '0';
            return;
        }

        makeString(n - 1, temp);

        string rev = temp;
        temp += '1';

        for(int i=0;i<rev.size();i++){
            if(rev[i]=='0') rev[i]='1';
            else rev[i]='0';
        }
        reverse(rev.begin(), rev.end()); // Reverse the copy (rev) instead of original temp
        temp += rev;
    }

    char findKthBit(int n, int k) {

        string temp = "";
        makeString(n, temp);

        // cout << temp << endl;
        return temp[k - 1]; // Return the kth bit (0-based index, so use k-1)
    }
};
