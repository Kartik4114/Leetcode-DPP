class Solution {
public:
    static bool comp(pair<int,double> &p1, pair<int,double> &p2) {
        double ratio1 = (double)(p1.first)/double(p1.second);
        double ratio2 = (double)(p2.first)/ double(p2.second);
        return ratio1 > ratio2;
    }

    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<int, double>> store;
        long long totalDamage = 0;

        for(auto it: damage) totalDamage += it; // calculate total damage
        for(int i=0;i<damage.size();i++){
            int time; // time required to kill ith enemy
            if(health[i]%power==0) time= health[i]/power;
            else time= health[i]/power+1;
            store.push_back({damage[i],time});
        }

        sort(store.begin(), store.end(), comp);

        long long ans = 0;
        for (auto &it : store) {
            double time = it.second;
            int d = it.first;
            ans += time * totalDamage;
            totalDamage -= d;
        }

        return ans;
    }
};
