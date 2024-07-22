class Solution {
public:
    vector<vector<int>> directions{{-1,0},{0,1},{1,0},{0,-1}};
    int memo[101][101];
    int a1(vector<vector<char>>& maze,vector<int> &entrance,int i,int j){
        
        int m=maze.size();
        int n=maze[0].size();
        if(i<0 || i>=m || j<0 || j>=n || maze[i][j]=='+') return INT_MAX;

        if(( i==0 || i==m-1 || j==0 || j==n-1) && (i!=entrance[0] || j!=entrance[1]) && maze[i][j]=='.'){
            return 0;
        }

        if(memo[i][j]!=-1) return memo[i][j];
        maze[i][j]='+';

        int mini=INT_MAX;
        for(auto &dir:directions){

            int new_i=i+dir[0];
            int new_j=j+dir[1];

            int result=a1(maze,entrance,new_i,new_j);
            if(result!=INT_MAX)
                mini=min(mini,1+result);
        }
        maze[i][j]='.';
        return memo[i][j]= mini;
    }
    
    int a2(vector<vector<char>>& maze, vector<int>& entrance){

        int m=maze.size();
        int n=maze[0].size();

        queue<pair<int,int>> que;
        que.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';

        int steps=0;

        while(!que.empty()){
            int N=que.size();

            while(N--){
                auto temp=que.front();
                que.pop();

                int i=temp.first;
                int j=temp.second;

                if(temp!=make_pair(entrance[0],entrance[1]) && (i==0 || j==0 || i==m-1 || j==n-1)){
                    return steps;
                }

                for(auto &dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && maze[new_i][new_j]=='.'){
                        maze[new_i][new_j]='+';
                        que.push(make_pair(new_i,new_j));
                    }
                }

            }
            steps++;
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        

        // here this DFS or recursive + memo. giving TLE
        // APPROACH 1:- giving TLE
        // memset(memo,-1,sizeof(memo));
        // int ans= a1(maze,entrance,entrance[0],entrance[1]);
        // return ans==INT_MAX ? -1 : ans;

        // APPROACH 2:- USING BFS (when shortest path is there always go for BFS)
        return a2(maze,entrance);
    }
};