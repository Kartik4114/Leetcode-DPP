class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();

        unordered_set<int> columnSet;
        
        vector<int> result;
        for(int i=0;i<m;i++){
            
            int minElement=INT_MAX;
            for(int j=0;j<n;j++){
                minElement=min(minElement,matrix[i][j]);
            }
            columnSet.insert(minElement);
        }

        for(int i=0;i<n;i++){
            int maxElement=-1;
            for(int j=0;j<m;j++){

                maxElement=max(maxElement,matrix[j][i]);
            }
            if(columnSet.find(maxElement)!=columnSet.end()){
                result.push_back(maxElement);
            }
        }

        return result;
    }
};