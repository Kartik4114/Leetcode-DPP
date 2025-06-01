class Solution {
public:
    int n;

    pair<int,int> getCoords(int num){

        int RT=(num-1)/n;
        int RB=(n-1)-RT;

        int col=(num-1)%n;

        if(n%2==RB%2){
            col = (n-1)-col;
        }

        return make_pair(RB,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();

        int steps=0;

        queue<int> que;

        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[n-1][0]=true;
        que.push(1);


        // starting with the BFS code
        while(!que.empty()){

            int N=que.size();

            while(N--){

                int x=que.front();
                que.pop();

                if(x==n*n){
                    return steps;
                }

                for(int k=1;k<=6;k++){

                    if(x+k>n*n) break;

                    auto coord=getCoords(x+k);

                    int r=coord.first;
                    int c=coord.second;

                    if(visited[r][c]) continue;
                    visited[r][c]=true;

                    if(board[r][c]!=-1){
                        que.push(board[r][c]);
                    } else {
                        que.push(x+k);
                    }
                }
            }

            steps++;
        }

        return -1;   
    }
};