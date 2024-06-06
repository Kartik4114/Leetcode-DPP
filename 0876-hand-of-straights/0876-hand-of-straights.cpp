#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int, int> mp;
        for(auto num : hand){
            mp[num]++;
        }

        for(auto it = mp.begin(); it != mp.end(); ++it){
            while(it->second > 0){
                int count = it->second;
                for(int i = 0; i < groupSize; ++i){
                    if(mp[it->first + i] < count){
                        return false;
                    }
                    mp[it->first + i] -= count;
                }
            }
        }

        return true;
    }
};
