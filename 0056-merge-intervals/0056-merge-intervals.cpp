class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n=intervals.size();

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> result;

        result.push_back(intervals[0]);
        for(int i=1;i<n;i++){
     
            if(intervals[i][0]<=result.back()[1]){
                
                vector<int> temp;
                int start=min(intervals[i][0],result.back()[0]);
                int end= max(intervals[i][1],result.back()[1]);

                result.pop_back();

                temp.push_back(start);
                temp.push_back(end);

                result.push_back(temp);    
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};