#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};

    int memo[101][101];
    int a1(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 1) return INT_MAX;
        if (i == n - 1 && j == n - 1) return 1;

     //   if (memo[i][j] != -1) return memo[i][j];

        grid[i][j] = 1; // Mark the cell as visited
        int ans = INT_MAX;
        for (auto& vec : directions) {
            int new_i = i + vec[0];
            int new_j = j + vec[1];
            int path = a1(grid, new_i, new_j);
            if (path != INT_MAX) {
                ans = min(ans, 1 + path);
            }
        }
        grid[i][j] = 0; // Unmark the cell

        return ans;
       // return memo[i][j] = ans;
    }

    int a2(vector<vector<int>> &grid){

        int m=grid.size();
        int n=grid[0].size();

        if(m==0 || n==0 || grid[0][0]!=0) return -1;

        queue<pair<int,int>> que;
        que.push({0,0});
        grid[0][0]=1;

        auto isSafe=[&](int x,int y){
            return x>=0 && y>=0 && x<m && y<n;
        };

        int level=0;
        while(!que.empty()){

            int N=que.size();
            while(N--){

                auto curr=que.front();
                que.pop();

                int x=curr.first;
                int y=curr.second;

                if(x==m-1 && y==n-1) return level+1;

                for(auto &dir:directions){
                    int new_x=x+dir[0];
                    int new_y=y+dir[1];

                    if(isSafe(new_x,new_y) && grid[new_x][new_y]==0){
                        que.push({new_x,new_y});
                        grid[new_x][new_y]=1;
                    }
                }
            }
            level++; 
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        // REMEMBER IF YOU TRYING TO USE HERE RECURSION THEN IT WILL GIVE TLE
        // AND IF YOU WILL USE MEMOIZATION THEN THAT WILL GIVE WRONG RESULT
        // BEC. THEIR MAY BE POSSIBILITY THAT THE PATH THEY EXPLORED AND THAT WE STORED IN ARRAY
        // IS LONGER.
        // SO USE BFS // ALTHOUGH CODE IS GIVEN

        // TLE

        // memset(memo, -1, sizeof(memo));
        // int result = a1(grid, 0, 0);
        // return result == INT_MAX ? -1 : result;

        // APPROACH 2:- USING BFS

        return a2(grid);
    }
};
