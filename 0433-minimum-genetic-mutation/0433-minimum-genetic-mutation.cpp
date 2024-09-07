class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string> bankSet(bank.begin(),bank.end());
        unordered_set<string> visited;
        queue<string> que;

        int level=0;
        que.push(startGene);
        visited.insert(startGene);

        while(!que.empty()){

            int n=que.size();
            while(n--){

                auto curr=que.front();
                que.pop();

                if(curr==endGene) return level;

                for(auto &ch:"ACGT"){
                    for(int i=0;i<curr.length();i++){
                        string neighbor=curr;
                        neighbor[i]=ch;

                        if(visited.find(neighbor)==visited.end() && bankSet.find(neighbor)!=bankSet.end()){
                            que.push(neighbor);
                            visited.insert(neighbor);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};