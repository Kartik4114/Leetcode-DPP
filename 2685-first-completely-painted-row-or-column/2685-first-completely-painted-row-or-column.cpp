class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();

        map<int,pair<int,int>> storeIndices;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                storeIndices[mat[i][j]]={i,j};
            }
        }

        map<int,int> row;
        map<int,int> col;

        for(int i=0;i<arr.size();i++){

            auto P=storeIndices[arr[i]];

            int r=P.first;
            int c=P.second;

            row[r]++;
            col[c]++;

            if(row[r]==n || col[c]==m){
                return i;
            }
        }

        return 0;

        
    }
};