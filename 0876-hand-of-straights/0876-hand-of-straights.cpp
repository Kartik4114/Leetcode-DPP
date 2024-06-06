#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> mp;
        for (auto num : hand) {
            mp[num]++;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int curr = it->first;
            int count = it->second;

            if (count > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (mp[curr + i] < count) return false;
                    mp[curr + i] -= count;
                }
            }
        }

        return true;
    }
};
