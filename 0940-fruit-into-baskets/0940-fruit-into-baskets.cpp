class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n=fruits.size();

        unordered_map<int,int> mp;

        int i=0;
        int j=0;

        int maxFruitCnt=0;
        while(j<n){

            mp[fruits[j]]++;

            while(i<n && mp.size()>2){

                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            
            maxFruitCnt=max(maxFruitCnt,j-i+1);
            j++;
        }

        return maxFruitCnt;
    }
};