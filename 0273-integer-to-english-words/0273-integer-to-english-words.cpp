#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string numberToWords(int n) {
        if (n == 0) return "Zero";
        
        unordered_map<int, string> singleRepresent;
        unordered_map<int, string> doubleRepresent;

        singleRepresent[1] = "One";
        singleRepresent[2] = "Two";
        singleRepresent[3] = "Three";
        singleRepresent[4] = "Four";
        singleRepresent[5] = "Five";
        singleRepresent[6] = "Six";
        singleRepresent[7] = "Seven";
        singleRepresent[8] = "Eight";
        singleRepresent[9] = "Nine";
        singleRepresent[10] = "Ten";
        singleRepresent[11] = "Eleven";
        singleRepresent[12] = "Twelve";
        singleRepresent[13] = "Thirteen";
        singleRepresent[14] = "Fourteen";
        singleRepresent[15] = "Fifteen";
        singleRepresent[16] = "Sixteen";
        singleRepresent[17] = "Seventeen";
        singleRepresent[18] = "Eighteen";
        singleRepresent[19] = "Nineteen";
        singleRepresent[20] = "Twenty";

        doubleRepresent[2] = "Twenty";
        doubleRepresent[3] = "Thirty";
        doubleRepresent[4] = "Forty";
        doubleRepresent[5] = "Fifty";
        doubleRepresent[6] = "Sixty";
        doubleRepresent[7] = "Seventy";
        doubleRepresent[8] = "Eighty";
        doubleRepresent[9] = "Ninety";

        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        string result = "";
        int thousandCounter = 0;

        while (n > 0) {
            if (n % 1000 != 0) {
                result = helper(n % 1000, singleRepresent, doubleRepresent) + thousands[thousandCounter] + " " + result;
            }
            n /= 1000;
            thousandCounter++;
        }

        while (result.back() == ' ') result.pop_back();
        return result;
    }

private:
    string helper(int num, unordered_map<int, string>& singleRepresent, unordered_map<int, string>& doubleRepresent) {
        string part = "";

        if (num >= 100) {
            part += singleRepresent[num / 100] + " Hundred ";
            num %= 100;
        }

        if (num >= 20) {
            part += doubleRepresent[num / 10] + " ";
            if (num % 10 > 0) part += singleRepresent[num % 10] + " ";
        } else if (num > 0) {
            part += singleRepresent[num] + " ";
        }

        return part;
    }
};
