class Solution {
public:
    vector<int> solve(string exp) {
        int n = exp.size();
        vector<int> result;
        
        for(int i = 0; i < n; i++) {
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
                vector<int> leftSubstr = solve(exp.substr(0, i));
                vector<int> rightSubstr = solve(exp.substr(i + 1));
                
                for(int &x : leftSubstr) {
                    for(int &y : rightSubstr) {
                        if(exp[i] == '+') {
                            result.push_back(x + y);
                        } else if(exp[i] == '-') {
                            result.push_back(x - y);
                        } else {
                            result.push_back(x * y);
                        }
                    }
                }
            }
        }
        
        // Base case: if there are no operators, just push the number
        if(result.empty()) {
            result.push_back(stoi(exp));
        }
        
        return result;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
