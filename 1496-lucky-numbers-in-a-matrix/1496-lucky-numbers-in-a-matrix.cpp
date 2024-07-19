class Solution {
public:
    vector<int> a1(vector<vector<int>>& matrix){
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

    vector<int> a2(vector<vector<int>>& matrix){

        int m=matrix.size();
        int n=matrix[0].size();

        int rMinMax=-1;
        for(int row=0;row<m;row++){
            
            int rMin=INT_MAX;
            for(int col=0;col<n;col++){
                rMin=min(rMin,matrix[row][col]);
            }

            rMinMax=max(rMinMax,rMin);  
        }

        int cMaxMin=INT_MAX;
        for(int col=0;col<n;col++){

            int cMax=-1;
            for(int row=0;row<m;row++){
                cMax=max(cMax,matrix[row][col]);
            }

            cMaxMin=min(cMaxMin,cMax);
        }

        if(rMinMax==cMaxMin)  return {rMinMax};
        return {};
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        // APPROACH 1:-
        // T.C :- O(N^2) , S.C :- O(n) 
        // return a1(matrix);

        // APPROACH 2:-  OPTIMISED APPROACH
        // here we are using the fact that there will be only one lucky number
        // T.C :- O(N^2) , S.C :-O(1)
        return a2(matrix);
    }
};