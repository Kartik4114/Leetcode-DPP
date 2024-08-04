class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }

        int width=1;
        int cnt=0;
        for(int i=0;i<colors.size()-1;i++){
            
            if(colors[i]!=colors[i+1]){
                width++;
            } else width=1;

            if(width>=k) cnt++;
        }
        return cnt;
    }
};